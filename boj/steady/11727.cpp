#include <iostream>

using namespace std;

int n;
int ans[1001] = {0, 1, 3,};

int main(void)
{
  cin >> n;
  for(int i = 3 ; i <= n ; i++)
  {
    // i번째 경우 = i-1번째에 2x1 놓기 + i-2번째에 x 2번(2x2 / 1x2 두개 놓기)
    ans[i]      = (ans[i-1]        + ans[i-2] * 2) % 10007;
  }
  cout << ans[n] << '\n';
}
