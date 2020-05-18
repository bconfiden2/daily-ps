#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n = 0;
  cin >> n;
  int data = 0;

  // 입력받는 수들을 차례대로 저장해 둔다.
  vector<int> v;
  v.reserve(n);
  for(int i = 0 ; i < n ; i++)
  {
    cin >> data;
    v.emplace_back(data);
  }

  // 1부터 시작해서 다른 벡터(스택역할)에 하나씩 넣으면서 위의 수열과 비교
  int i = 0; // 위의 수열에 대한 인덱스값
  int next = 1; // 스택에 넣을 다음 원소값
  int cur = -1; // 스택이 현재 가리키고 있는 위치
  vector<int> vstack;
  string ans = ""; // 출력용 답
  while(i < n) // 기준 수열을 다 돌 때 까지
  {
    if(next > n) // 만약 다 돌았는데 안끝났으면 답은 NO 이므로 빠져나간다.
    {
      ans = "NO";
      break;
    }
    vstack.push_back(next++); // 스택에 현재 원소값을 넣고
    cur++; // 스택 현재 인덱스
    ans += "+\n"; // 푸시 했으니 + 하나 추가
    while(vstack[cur] == v[i] && v[i] != 0) // 현재 스택 인덱스와 기준 수열의 인덱스 비교
    {
      vstack.pop_back(); // 같을 경우 하나 뺴주고
      cur--; // 스택에서 하나 뺐으니 감소
      i++; // 하나 일치했으니 기준 수열 인덱스는 다음 값으로
      ans += "-\n"; // - 하나 추가
    }
  }
  cout << ans;
}
