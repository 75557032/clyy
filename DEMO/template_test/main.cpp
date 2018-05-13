#include <QCoreApplication>
#include <QDebug>

template <typename T, bool>
struct CBase
{

};

template <typename T>
struct CBase<T, true>
{
    CBase(){qDebug() << "true";}
};

template <typename T>
struct CBase<T, false>
{
    CBase(){qDebug() << "false";}
};

template <typename T, size_t N = sizeof(T)>
struct CTest
{
    static void test() { qDebug() << "M"; }
};

template <typename T>
struct CTest<T, 1>
{
    static void test() { qDebug() << "S"; }
};

template <typename T>
struct CChar
{
    static void test() { qDebug() << "M"; }
};

template <>
struct CChar<char>
{
    static void test() { qDebug() << "S"; }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CBase<int, true> aa;
    CBase<int, false> bb;

    CTest<int>::test();
    CTest<quint8>::test();
    CTest<char>::test();
    CTest<signed char>::test();

    CChar<char>::test();
    CChar<signed char>::test();

    return a.exec();
}
