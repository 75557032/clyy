#include <stdio.h>
#include <stdlib.h>

static void test_1()
{
    printf("test_1\n");
}
static void test_2()
{
    printf("test_2\n");
}

typedef void (*tt)();

static tt a1 __attribute((__section__("clyy"))) = test_1;
static tt a2 __attribute((__section__("clyy"))) = test_2;

extern void __start_clyy, __stop_clyy;

int main()
{
    tt *i = &__start_clyy;
    for (; i != &__stop_clyy; ++i) {
            (*i)();
    }
    return 0;
}
