#include <iostream>
using namespace std;

// 입력된 숫자의 갯수를 담을 배열
int nums[10001];

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 0 ;
  cin >> n;
  int data;
  // 입력된 숫자를 인덱스로 써서 갯수 증가
  for(int i = 0 ; i < n ; i++)
  {
    cin >> data;
    nums[data]++;
  }
  // 1~10000 까지 순서대로 저장된 갯수 만큼 출력
  for(int idx = 1 ; idx <= 10000 ; idx++)
  {
    for(int i = 0 ; i < nums[idx] ; i++)
    {
      cout << idx << '\n';
    }
  }
}
