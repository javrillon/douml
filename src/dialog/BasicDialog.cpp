// *************************************************************************
//
// Copyright 2004-2010 Bruno PAGES  .
// Copyright 2012-2013 Nikolai Marchenko.
// Copyright 2012-2013 Leonardo Guilherme.
//
// This file is part of the DOUML Uml Toolkit.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License Version 3.0 as published by
// the Free Software Foundation and appearing in the file LICENSE.GPL included in the
//  packaging of this file.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License Version 3.0 for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// e-mail : doumleditor@gmail.com
// home   : http://sourceforge.net/projects/douml
//
// *************************************************************************





#include <gridbox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include "BasicDialog.h"
#include "BasicData.h"
#include "BrowserNode.h"
#include "UmlWindow.h"
#include "DialogUtil.h"
#include "KeyValueTable.h"
#include "UmlDesktop.h"
#include "BodyDialog.h"
#include "strutil.h"
#include "ProfiledStereotypes.h"
#include "translate.h"
#include "vvbox.h"
#include "hhbox.h"
BasicDialog::BasicDialog(BasicData * nd, QString s,
                         const QStringList & default_stereotypes,
                         QSize & sz, bool unnamed)
    : TabDialog(0, 0, FALSE, Qt::WA_DeleteOnClose), data(nd), previous_size(sz)
{
    setAttribute(Qt::WA_DeleteOnClose);
    nd->get_browser_node()->edit_start();

    if (nd->get_browser_node()->is_writable()) {
        setOkButton(tr("OK"));
        setCancelButton(tr("Cancel"));
    }
    else {
        setOkButton(QString());
        setCancelButton(tr("Close"));
    }

    setWindowTitle(s + tr(" dialog"));
    bool visit = !hasOkButton();

    // general tab

    BrowserNode * bn = data->get_browser_node();
    GridBox * grid = new GridBox(2, this);
    grid->setMargin(0);
    grid->setSpacing(0);

    if (unnamed)
        edname = 0;
    else {
        grid->addWidget(new QLabel(tr("name : "), grid));
        grid->addWidget(edname = new LineEdit(bn->get_name(), grid));
        edname->setReadOnly(visit);
    }

    grid->addWidget(new QLabel(tr("stereotype : "), grid));
    grid->addWidget(edstereotype = new QComboBox(grid));
    edstereotype->setEditable(!visit);
    edstereotype->addItem(toUnicode(data->get_stereotype()));

    if (! visit) {
        edstereotype->addItems(default_stereotypes);
        edstereotype->addItems(ProfiledStereotypes::defaults(bn->get_type()));
        edstereotype->setAutoCompletion(completion());
    }

    edstereotype->setCurrentIndex(0);
    QSizePolicy sp = edstereotype->sizePolicy();
    sp.setHorizontalPolicy(QSizePolicy::Expanding);
    edstereotype->setSizePolicy(sp);

    VVBox * vtab = new VVBox(grid);
    grid->addWidget(vtab);
    vtab->addWidget(new QLabel(tr("description :"), vtab));

    SmallPushButton *sButton;
    if (! visit)
    {
        connect(sButton = new SmallPushButton(tr("Editor"), vtab), SIGNAL(clicked()),
                this, SLOT(edit_description()));
        vtab->addWidget(sButton);
    }

    grid->addWidget(comment = new MultiLineEdit(grid));
    comment->setReadOnly(visit);
    comment->setText(bn->get_comment());
    QFont font = comment->font();

    if (! hasCodec())
        font.setFamily("Courier");

    font.setFixedPitch(TRUE);
    comment->setFont(font);

    addTab(grid, "Uml");

    // USER : list key - value

    grid = new GridBox(2, this);
    grid->setMargin(5);
    grid->setSpacing(5);

    kvtable = new KeyValuesTable(bn, grid, visit);
    grid->addWidget(kvtable);
    addTab(grid, QObject::tr("Properties"));
    open_dialog(this);
}

void BasicDialog::polish()
{
    TabDialog::ensurePolished();
    UmlDesktop::limitsize_move(this, previous_size, 0.8, 0.8);
}

BasicDialog::~BasicDialog()
{
    data->get_browser_node()->edit_end();
    previous_size = size();

    foreach (BodyDialog *dialog, edits)
        dialog->close();
    edits.clear();

    close_dialog(this);
}

void BasicDialog::edit_description()
{
    edit(comment->text(),
         (edname == 0) ? QString("description")
         : edname->text().trimmed() + "_description",
         data, TxtEdit, this, (post_edit) post_edit_description, edits);
}

void BasicDialog::post_edit_description(BasicDialog * d, QString s)
{
    d->comment->setText(s);
}

void BasicDialog::accept()
{
    if (!check_edits(edits) || !kvtable->check_unique())
        return;

    BrowserNode * bn = data->get_browser_node();

    if (edname != 0) {
        QString s = edname->text().trimmed();

        if ((s != bn->get_name()) &&
            ((BrowserNode *) bn->parent())->wrong_child_name(s, bn->get_type(),
                    bn->allow_spaces(),
                    bn->allow_empty())) {
            msg_critical(tr("Error"), edname->text() + QObject::tr("\n\nillegal name or already used"));
            return;
        }
        else
            bn->set_name(s);
    }
    bool newst = data->set_stereotype(fromUnicode(edstereotype->currentText().trimmed().toLatin1().constData()));
    bn->set_comment(comment->text());
    UmlWindow::update_comment_if_needed(bn);

    kvtable->updateNodeFromThis(bn);

    ProfiledStereotypes::modified(bn, newst);

    bn->package_modified();
    data->modified();
    TabDialog::accept();
}
