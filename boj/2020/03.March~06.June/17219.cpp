#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  map<string, string> ma;
  int n, m;
  cin >> n >> m;
  // 각 사이트를 키로, 비밀번호를 값으로 해서 맵에 저장
  for(int i = 0 ; i < n ; i++)
  {
    string site, pw;
    cin >> site >> pw;
    ma.insert(pair<string, string>(site, pw));
  }
  // 사이트를 입력받아 비밀번호를 출력
  for(int i = 0 ; i < m ; i++)
  {
    string ans;
    cin >> ans;
    cout << ma[ans] << '\n';
  }
}
