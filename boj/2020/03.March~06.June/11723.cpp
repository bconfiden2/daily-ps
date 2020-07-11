#include <iostream>
#include <string>
#include <set>
using namespace std;

int m;
string line;
int value;
bool ans[21];

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> m;
  while(m--)
  {
    cin >> line;
    switch(line[1])
    {
      // add, 해당 인덱스 무조건 true
      case 'd' :
        cin >> value;
        ans[value] = true;
        break;
      // remove, 해당 인덱스 무조건 false
      case 'e' :
        cin >> value;
        ans[value] = false;
        break;
      // check, 해당 인덱스 값 출력
      case 'h' :
        cin >> value;
        if(ans[value]) cout << 1 << '\n';
        else cout << 0 << '\n';
        break;
      // toggle, 해당 인덱스값만 뒤집어줌
      case 'o' :
        cin >> value;
        ans[value] = !ans[value];
        break;
      // all, 전부 채워줌
      case 'l' :
        for(int i = 1 ; i < 21 ; i++)
        {
          ans[i] = true;
        }
        break;
      // empty, 전부 비워줌
      case 'm' :
        for(int i = 1 ; i < 21 ; i++)
        {
          ans[i] = false;
        }
        break;
     }
  }
}
