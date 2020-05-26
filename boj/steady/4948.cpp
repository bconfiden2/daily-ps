#include <iostream>

using namespace std;

int n = 0;
int che[247000] = {1,1};

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 에라토스테네스의 체
  for(int i = 2 ; i < 247000 ; i++)
  {
    if(che[i] == 0)
    {
      for(int j = 2 ; i * j < 247000 ; j++)
      {
        che[i*j] = 1;
      }
    }
  }

  // 너무 쉽다!
  cin >> n;
  while(n)
  {
    int cnt = 0;
    for(int i = n+1 ; i <= 2*n ; i++)
    {
      if(che[i] == 0) cnt++;
    }
    cout << cnt << '\n';

    cin >> n;
  }
}
