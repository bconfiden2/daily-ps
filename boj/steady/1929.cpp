#include <iostream>

using namespace std;

int n, m;
int che[1000001] = {1, 1};

int main(void)
{
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin >> n >> m;
  // 에라토스테네스의 체
  for(int i = 2 ; i < 1000001 ; i++)
  {
    if(che[i] == 1)
    {
      continue;
    }
    int idx = 2;
    while(i * idx <= 1000000)
    {
      che[i * idx++] = 1;
    }
  }

  for(int i = n ; i <= m ; i++)
  {
    if(!che[i]) cout << i << '\n';
  }
}
