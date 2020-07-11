#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string s;
  // 크로아티아 문자
  string w[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
  cin >> s;

  // 각 크로아티아 문자들을 다 비교해줌
  for(int i = 0 ; i < 8 ; i++)
  {
    // 문자열에서 아무것도 안나올때까지
    while(s.find(w[i]) != string::npos)
    {
      // 해당 크로아티아 문자를 찾아서 아무 관련 없는 k 라는 문자로 치환
      s.replace(s.find(w[i]), w[i].size(), "k");
    }
  }

  cout << s.size() << endl;
}
