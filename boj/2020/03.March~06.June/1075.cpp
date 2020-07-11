#include <iostream>
using namespace std;

int main(void)
{
  int n, f;
  cin >> n >> f;
  // 입력받은 n 값의 뒤 2자리 수를 00 으로 바꿔주고 f 로 나눈 나머지
  int ans = n / 100 * 100 % f;
  // 만약 f 로 나눠떨어지지 않는다면 나눠떨어지는 값으로 바꿔줌
  if(ans != 0) ans = f - ans;
  if(ans < 10) cout << '0' << ans << endl;
  else cout << ans << endl;
}
