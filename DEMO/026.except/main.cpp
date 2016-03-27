#include <iostream>
#include <signal.h>
#include <setjmp.h>

using namespace std;

static jmp_buf xx;

void fphandler( int sig)
{
  cout << "aaa" << endl;
  longjmp(xx,1);
}

void test()
{
  if (1==setjmp(xx))
  {
    int a=1,b=0,c;
    try
    {
      c=a/b;
      cout << "yyy" << endl;
    }catch(...)
    {
      cout << "xxx" << endl;
    }
  }
}

int main()
{
  signal( SIGFPE, fphandler );
  test();
  cout << "Hello world!" << endl;
  return 0;
}
