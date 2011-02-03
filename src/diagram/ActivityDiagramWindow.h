// *************************************************************************
//
// Copyright 2004-2010 Bruno PAGES  .
//
// This file is part of the BOUML Uml Toolkit.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// e-mail : bouml@free.fr
// home   : http://bouml.free.fr
//
// *************************************************************************

#ifndef ACTIVITYDIAGRAMWINDOW_H
#define ACTIVITYDIAGRAMWINDOW_H

#include "DiagramWindow.h"

class QToolButton;
class QSpinBox;

class ActivityDiagramView;
class BrowserActivityDiagram;

class ActivityDiagramWindow : public DiagramWindow {
  Q_OBJECT
    
  protected:
    ActivityDiagramView * view;
    QToolButton * addActivity;
    QToolButton * addInterruptibleActivityRegion;
    QToolButton * addExpansionRegion;
    QToolButton * addActivityPartition;
    QToolButton * addInitial;
    QToolButton * addActivityFinal;
    QToolButton * addFlowFinal;
    QToolButton * addDecision;
    QToolButton * addMerge;
    QToolButton * addFork;
    QToolButton * addJoin;
    QToolButton * addAction;
    QToolButton * addObject;
    QToolButton * addFlow;
    QToolButton * dependency;
    QToolButton * addPackage;
    QToolButton * addFragment;
    QToolButton * note;
    QToolButton * anchor;
    QToolButton * text;
    QToolButton * image;
  
  public:
    ActivityDiagramWindow(const QString & s, BrowserActivityDiagram * b, int id = -1);
virtual ~ActivityDiagramWindow();

    virtual DiagramView * get_view() const;
    
    virtual void hit_button(UmlCode, QToolButton *);
    
  protected slots:
    void hit_activity();
    void hit_interruptibleactivityregion();
    void hit_expansionregion();
    void hit_activitypartition();
    void hit_initial();
    void hit_activityfinal();
    void hit_flowfinal();
    void hit_decision();
    void hit_merge();
    void hit_fork();
    void hit_join();
    void hit_action();
    void hit_object();
    void hit_flow();
    void hit_dependency();
    void hit_package();
    void hit_fragment();
    void hit_note();
    void hit_anchor();
    void hit_text();
    void hit_image();
};

#endif
