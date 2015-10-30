#include <iostream>

using namespace std;

// 用于欺骗编译器，传递This指针
class CMemFunObj
{

};
// 通用函数类型
typedef void (CMemFunObj:: *PFNMEMFUN)(int a);
// 成员函数结构
typedef struct tagMEMBERFUN
{
    CMemFunObj *Self;
    PFNMEMFUN pfnAddr;
} MEMBERFUN, *PMEMBERFUN;
// 生成成员函数结构
MEMBERFUN MakeMemberFun(CMemFunObj *Self, PFNMEMFUN pfnAddr);
// 宏：生成成员函数结构
#define MAKEMEMFUN(Self, pfnAddr) MakeMemberFun((CMemFunObj*)Self, (PFNMEMFUN)pfnAddr)
// 宏：回调成员函数，FunType为具体函数类型，MemFun为成员函数结构
#define CALLMEMFUN(FunType, MemFun) (MemFun.Self->*(FunType)MemFun.pfnAddr)
// 宏：判断成员函数结构是否有值
#define ISMEMFUNASSIGNED(MemFun) (MemFun.Self != NULL) && (MemFun.pfnAddr != NULL)

MEMBERFUN MakeMemberFun(CMemFunObj *Self, PFNMEMFUN pfnAddr)
{
    MEMBERFUN Memfun;
    Memfun.pfnAddr = pfnAddr;
    Memfun.Self = Self;
    return Memfun;
}

class RecvTest
{
public:
    MEMBERFUN m_OnRunProcess;
    void xxx(int a)
    {
        if (ISMEMFUNASSIGNED(m_OnRunProcess))
            CALLMEMFUN(PFNMEMFUN, m_OnRunProcess)(a);
    }
};

class SendTest
{
private:
    int b=0;
public:
    void TestEvent(int a)
    {
        this->b=this->b+a;
        cout << this->b <<endl;
    }
};

int main()
{
    SendTest send;
    RecvTest recv;
    MEMBERFUN tmp = MAKEMEMFUN(&send, &send.TestEvent);
    recv.m_OnRunProcess=tmp;
    recv.xxx(1);
    recv.xxx(1);
    return 0;
}
