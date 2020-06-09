#include <iostream>

using namespace std;

int a,b;

int main(void)
{
  while(true)
  {
    cin >> a >> b;
    if(a==0 && b==0)
    {
      break;
    }
    // 둘 중 하나라도 0 이 입력된 경우 에러발생하기때문에 따로 처리
    if(a == 0 || b == 0)
    {
      cout << "neither" << '\n';
      continue;
    }
    // 3개 케이스 각각 처리
    if(b % a == 0) cout << "factor" << '\n';
    else if(a % b == 0) cout << "multiple" << '\n';
    else cout << "neither" << '\n';
  }
}
