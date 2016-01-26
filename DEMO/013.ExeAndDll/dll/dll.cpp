#include <QDebug>
#include <QTcpSocket>
#include "dll.h"
//////////////////////////////////
class clyy
{
public:
    QTcpSocket socket;
    void test()
    {
        qDebug() << socket.socketDescriptor();
    }
};
/////////////////////////////////这个区间你可以独立成一个头文件供你内部用
Dll::Dll()
{
}

void Dll::test()
{
    qDebug() << "test";
    clyy a;
    a.test();
}
