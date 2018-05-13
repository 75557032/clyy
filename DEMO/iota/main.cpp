#include <QCoreApplication>
#include <QDebug>

#include <numeric>
#include <vector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> b(5);
    iota(b.begin(), b.end(), 1);

    for (auto it = b.begin(); it != b.end(); ++it) {
        qDebug() << *it;
    }

    return a.exec();
}
