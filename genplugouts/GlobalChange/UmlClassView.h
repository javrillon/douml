#ifndef _UMLCLASSVIEW_H
#define _UMLCLASSVIEW_H


#include "UmlBaseClassView.h"


class Context;

// This class manages 'class view'
//
// You can modify it as you want (except the constructor)
class UmlClassView : public UmlBaseClassView
{
public:
    UmlClassView(void * id, const QByteArray & n) : UmlBaseClassView(id, n) {};

    virtual void change(Context & ctx);

};

#endif
