#include <cstdio>
using namespace std;
int func(int n)
{
  if(n==1) return 1;
  else if(n==3) return 2;
  else if(n%2==0) return func(n/2)*2;
  else{int a = func(n/2)*2+2;return a>2*(n/2)?2:a;}
}
int main(void)
{
  int n = 0;
  scanf("%d",&n);
  printf("%d\n",func(n));
}
