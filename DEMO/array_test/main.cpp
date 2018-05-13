#include <QCoreApplication>

static void test(char (&xx)[3])
{
    //
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char xx[3];
    test(xx);
    char *pxx = new char[3];
    test(*((char (*)[3])pxx));

    char bxx[5];
    test(*((char (*)[3])&bxx[1]));

    return a.exec();
}
