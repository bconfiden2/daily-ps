#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
  int n, k;
  int ans, at = 0;

  scanf("%d %d", &n ,&k);

  // 벡터를 최대갯수인 1000개 설정해놓고 초기화
  vector<int> v(1000);
  for(int i = 0 ; i < n ; i++)
  {
    v[i] = i + 1;
  }

  int curSize = n;
  printf("<");
  // 1명 남을때까지 반복, 마지막 1명은 끝나고 출력
  while(curSize > 1)
  {
    // at 은 이번 반복 때 제거할 사람을 가리킨다
    // k - 1 을 더하는 이유는 이전 at 을 가리키던 사람이 지워지기 때문에,
    // 지워졌던 사람까지 포함하여 생각하기 위해서이다
    at += k - 1;
    // 가리키는 위치가 전체 사람 수를 넘어갈 경우,계속 앞으로 돌려보낸다
    while(at >= curSize)
    {
      at -= curSize;
    }
    ans = v[at];

    // 지워준다
    v.erase(v.begin() + at);

    printf("%d, ", ans);
    curSize--;
  }
  printf("%d>\n", v[0]);
}
