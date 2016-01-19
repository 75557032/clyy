#ifndef CLYYEVENT_H
#define CLYYEVENT_H

#include <QEvent>

//static const QEvent::Type clyyEventType = (QEvent::Type)QEvent::registerEventType(QEvent::User+100);
static const QEvent::Type clyyEventType = (QEvent::Type)(QEvent::User+100);

class clyyEvent : public QEvent
{
public:
    clyyEvent(Type clyyEventType):QEvent(clyyEventType){}
    int res;
};

#endif // CLYYEVENT_H
