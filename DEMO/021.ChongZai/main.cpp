#include <iostream>

using namespace std;

class CLYY
{
public:
    int a;
};

inline int operator + (CLYY &A,int B)
{
    return A.a - B;
}

int main()
{
    CLYY a;
    a.a=10;
    int b=9;
    cout << "aa" << endl;
    cout << a+b << endl;
    return 0;
}
