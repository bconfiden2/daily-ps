#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
// 숫자 인덱스를 이용해 문자열을 가져오기 위한 벡터
vector<string> v;
// 문자열을 키로 사용해 숫자를 가져오기 위한 맵(딕셔너리)
map<string, int> ma;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int ansIdx;
  string ansStr;
  string name;
  // 포켓몬들 정보 입력 부분
  for(int i = 0 ; i < n ; i++)
  {
    cin >> name;
    v.emplace_back(name);
    ma.insert(pair<string, int>(name, i+1));
  }

  for(int i = 0 ; i < m ; i++)
  {
    cin >> ansStr;
    // 만약 입력된 문자열이 숫자라면
    if(atoi(ansStr.c_str()))
    {
      // 숫자로 바꿔준다음 해당 인덱스로 값을 출력
      ansIdx = stoi(ansStr);
      cout << v[ansIdx - 1] << '\n';
    }
    // 숫자가 아닐 경우 맵의 키값으로 사용하여 번호 출력
    else
    {
      cout << ma[ansStr] << '\n';
    }
  }
}
