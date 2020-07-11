#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int key[9];
  int sum = 0;
  // 9명 입력받고 총합 구해준뒤
  for(int i = 0 ; i < 9 ; i++)
  {
    cin >> key[i];
    sum += key[i];
  }
  // 정렬을 먼저 해준다
  sort(key, key + 9);
  // 2명의 합이 나와야 할 값
  int tar = sum - 100;
  for(int i = 0 ; i < 9 ; i++)
  {
    bool end = false;
    for(int j = i + 1 ; j < 9 ; j++)
    {
      // 2중반복을 전체를 돌며 2명의 합 구하고
      if(key[i] + key[j] == tar)
      {
        // 둘 다 0으로 바꿔준 뒤 반복 종료
        key[i] = 0;
        key[j] = 0;
        end = true;
        break;
      }
    }
    if(end) break;
  }
  // 0 이 아닌 7명 난쟁이들을 출력
  for(int i = 0 ; i < 9 ; i++)
  {
    if(key[i] != 0) cout << key[i] << '\n';
  }
}
