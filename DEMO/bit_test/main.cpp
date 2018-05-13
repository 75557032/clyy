#include <QCoreApplication>
#include <QDebug>

struct CTest
{
    unsigned short a1 : 2;
    unsigned short a2 : 7;
    unsigned short a3 : 7;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    unsigned short x = 0x0102;
    CTest *p = (CTest *)&x;
    qDebug("%x %x %x", p->a1, p->a2, p->a3);

    x = 0x0902;
    p = (CTest *)&x;
    qDebug("%x %x %x", p->a1, p->a2, p->a3);

    return a.exec();
}
