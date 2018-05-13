#include <QCoreApplication>
#include <QDebug>

#include <tuple>

std::tuple<double, char, QString> get_student(int id)
{
    if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto student0 = get_student(0);
    qDebug() << "ID: 0, "
             << "GPA: " << std::get<0>(student0) << ", "
             << "grade: " << std::get<1>(student0) << ", "
             << "name: " << std::get<2>(student0);

    double gpa1;
    char grade1;
    QString name1;
    std::tie(gpa1, grade1, name1) = get_student(1);
    qDebug() << "ID: 1, "
             << "GPA: " << gpa1 << ", "
             << "grade: " << grade1 << ", "
             << "name: " << name1;

//以下代码C++17支持
//    auto [ gpa2, grade2, name2 ] = get_student(2);
//    qDebug() << "ID: 2, "
//             << "GPA: " << gpa2 << ", "
//             << "grade: " << grade2 << ", "
//             << "name: " << name2 << '\n';

    return a.exec();
}
