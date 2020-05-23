#include <iostream>

using namespace std;

int n, m, b, data;
int minv = 256;
int maxv = 0;
int heights[257];
int temp[257];

int finish(int targetH)
{
  // 이번 계산에서 사용할 배열을 입력값으로 업데이트
  for(int i = 0 ; i < 257 ; i++)
  {
    temp[i] = heights[i];
  }
  // 메인에서 입력받은 변수들이 전역변수이기 때문에 해당 계산에서만 사용할 변수들로 바꿔줌
  int res = 0; // 이번 층을 만들기 위해 총 몇초가 걸렸는가
  int item = b; // 사용가능한 블록갯수, 해당 층으로 만들 수 있는지 확인
  int tempMin = minv;
  int tempMax = maxv;
  int tempv;

  // 아래에서부터 블록을 쌓으면서 만드는 과정
  while(tempMin != targetH)
  {
    tempv = temp[tempMin];
    // 이번 층을 쌓는데는 쌓여있는 갯수 만큼 시간이 걸림
    res += tempv;
    // 쌓아올렸으니 아이템 사용
    item -= tempv;
    // 위층으로 다 쌓았음
    temp[tempMin+1] += tempv;
    temp[tempMin++] = 0;
  }
  // 위에서부터 블록을 파내면서 만드는 과정
  while(tempMax != targetH)
  {
    tempv = temp[tempMax];
    // 파내는데는 갯수 * 2 초
    res += tempv * 2;
    // 파냈으니 아이템+
    item += tempv;
    // 아래층으로 파냈다는 뜻
    temp[tempMax-1] += tempv;
    temp[tempMax--] = 0;
  }
  // 기본 블록 + 파낸 블록 - 사용한 블록이 0보다 작으면 만들지 못한다는 뜻
  if(item < 0) return -1;

  return res;
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> b;
  // 각 배열은 블록 층별로 갯수들을 저장
  for(int i = 0 ; i < n * m ; i++)
  {
    cin >> data;
    heights[data]++;
  }
  // 최소값부터 최댓값 까지만 탐색하면 되므로 따로 저장해놓는다
  for(int i = 0 ; i < 257 ; i++)
  {
    if(heights[i] > 0)
    {
      if(i < minv) minv = i;
      if(i > maxv) maxv = i;
    }
  }

  int ans = 2000000000;
  int idx = 0;
  // 입력받은 데이터들을 각 층별로 전부 구해보고, 그 중 최솟값을 찾는다
  // 더 높은 층에서 같은 최솟값이 나오면 높은 층으로 적용
  for(int i = minv ; i <= maxv ; i++)
  {
    // 모든 블럭을 해당 층으로 만들기 위한 값
    int temp = finish(i);
    // -1 은 만들 수 없다는 뜻
    if(temp == -1) continue;
    // 최솟값 업데이트
    if(temp <= ans)
    {
      ans = temp;
      idx = i;
    }
  }
  cout << ans << " " << idx << '\n';
}
