#include <QCoreApplication>
#include <QDebug>
#include <QList>

/////////////////////////////////////方法1
static int test()
{
    qDebug() << "test";
    return 0;
}

static volatile int a = test();
/////////////////////////////////////

/////////////////////////////////////方法2，此方法可以控制顺序，控制执行的时机，也能用于释放的执行
typedef void (*inittype)();

static inittype initList[10] = {NULL};

static void test_1()
{
    qDebug() << "test_1";
}

static volatile inittype *b = new(&initList[0]) inittype(test_1);
/////////////////////////////////////


/////////////////////////////////////方法3，基本同方法2

static QList<inittype> init_list;

static void test_2()
{
    qDebug() << "test_2";
}

static char reg_init(inittype init)
{
    init_list.append(init);
    return '\0';
}

static volatile char c = reg_init(test_2);

/////////////////////////////////////

int main(int argc, char *argv[])
{
    qDebug() << "main";
    QCoreApplication a(argc, argv);
    for (int i = 0; i < 10; ++i) {
        if (NULL != initList[i]) {
            initList[i]();
        }
    }

    for (int i = 0; i < init_list.count(); ++i) {
        if (NULL != init_list.at(i)) {
            init_list.at(i)();
        }
    }
    return a.exec();
}
