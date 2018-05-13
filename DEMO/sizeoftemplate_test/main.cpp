#include <QCoreApplication>
#include <QDebug>
#include <array>
#include <initializer_list>

template<typename ...T>
static void test(T &&...a)
{
    qDebug() << sizeof...(a);
    auto b = { std::forward<T>(a)... };
    for (auto it = b.begin(); it != b.end(); ++it) {
        qDebug() << *it;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test<int>(1, 2, 3);

    return a.exec();
}
