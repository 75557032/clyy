#include <iostream>

using namespace std;

// ������ƭ������������Thisָ��
class CMemFunObj
{

};
// ͨ�ú�������
typedef void (CMemFunObj:: *PFNMEMFUN)(int a);
// ��Ա�����ṹ
typedef struct tagMEMBERFUN
{
    CMemFunObj *Self;
    PFNMEMFUN pfnAddr;
} MEMBERFUN, *PMEMBERFUN;
// ���ɳ�Ա�����ṹ
MEMBERFUN MakeMemberFun(CMemFunObj *Self, PFNMEMFUN pfnAddr);
// �꣺���ɳ�Ա�����ṹ
#define MAKEMEMFUN(Self, pfnAddr) MakeMemberFun((CMemFunObj*)Self, (PFNMEMFUN)pfnAddr)
// �꣺�ص���Ա������FunTypeΪ���庯�����ͣ�MemFunΪ��Ա�����ṹ
#define CALLMEMFUN(FunType, MemFun) (MemFun.Self->*(FunType)MemFun.pfnAddr)
// �꣺�жϳ�Ա�����ṹ�Ƿ���ֵ
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
