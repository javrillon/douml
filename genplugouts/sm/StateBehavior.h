#ifndef _STATEBEHAVIOR_H
#define _STATEBEHAVIOR_H


#include <QByteArray>

class StateBehavior
{
public:
    QByteArray on_entry;

    QByteArray on_exit;

    QByteArray do_activity;

    void read();

    void unload();

};

#endif
