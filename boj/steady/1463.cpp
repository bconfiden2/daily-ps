#include <iostream>

// 두 수 중 작은 값을 리턴
#define MINI(a,b) a < b ? a : b

using namespace std;

int n;
// n까지 각각 값을 구해놓을 배열
int arr[1000001] = {0, 0, 1, 1,};

int main(void)
{
  cin >> n;

  // 4번부터 시작
  for(int i = 4 ; i <= n ; i++)
  {
    // 이번의 최솟값은 1차적으로 보았을 때 직전꺼에서 1만 더해준 값이다
    arr[i] = arr[i-1] + 1; // 1을 빼던지
    // 그런데 만약 2로 나눠떨어질 경우에는 2로 나눈 인덱스의 값+1 과 비교해본다
    if(i % 2 == 0) // 2로 나누던지
    {
      arr[i] = MINI(arr[i/2] + 1, arr[i]);
    }
    // 만약 3으로 나눠떨어질 경우에도 확인해준다
    if(i % 3 == 0) // 3으로 나누던지
    {
      arr[i] = MINI(arr[i/3] + 1, arr[i]);
    }
    // 그러면 최종적으로 이번인덱스의 최솟값이 구해진다
  }

  cout << arr[n] << '\n';
}
