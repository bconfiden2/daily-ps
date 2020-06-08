#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string a;
  int sum = 0;
  cin >> a;
  for(int i = 0 ; i < a.length() ; i++)
  {
    // 일단 3으로 나눈 값을 기준으로 다 구하고
    sum += 3 + (int(a[i]) - 65) / 3;

    // 중간에 4개가 껴있는 경우가 있기 때문에 넘어가는 부분들에 대해서 처리
    switch(a[i])
    {
      case 'S' :
      case 'V' :
      case 'Y' :
      case 'Z' :
        sum--;
        break;
    }
  }
  cout << sum << endl;
}
