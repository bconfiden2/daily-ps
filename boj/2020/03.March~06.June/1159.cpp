#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  int num[26] = {0,}; // 각 문자들의 갯수 저장
  // 성씨의 첫번째 문자를 num 에 각각 저장
  for(int i = 0 ; i < n ; i++)
  {
    string s;
    cin >> s;
    num[s[0] - 97]++;
  }
  bool ok = false;
  // 5개 이상 나온 문자들을 순서대로 출력
  for(int i = 0 ; i < 26 ; i++)
  {
    if(num[i] >= 5)
    {
      cout << char(i+97);
      ok = true;
    }
  }
  if(!ok) cout << "PREDAJA";
  cout << endl;
}
