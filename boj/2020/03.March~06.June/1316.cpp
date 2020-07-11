#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  int n;
  cin >> n;

  int num = 0;
  for(int i = 0 ; i < n ; i++)
  {
    string s;
    cin >> s;
    // 그룹단어인지 판별 여부
    bool pos = true;
    // 문자열 각 문자별로 한번 쭉 돌건데
    for(int j = 0 ; j < s.size() ; j++)
    {
      // 이번 단어가 가장 마지막으로 나온 위치
      int last = j;
      // 나머지 문자열 중에 해당 단어가 또 나오는지 쭉 확인
      for(int k = j + 1 ; k < s.size() ; k++)
      {
        // 만약 같은 단어가 나왔는데
        if(s[j] == s[k])
        {
          // 현재 위치와 last 위치 차이가 1일경우 연속되었다는 뜻
          if(k - last == 1)
          {
            // 다음 문자열 검사때는 안해도되니 j 에 k 를 넣어주고
            j = k;
            // 마지막 위치도 변경
            last = k;
          }
          // 연속되지 않았을 경우
          else
          {
            // 그룹단어가 아님
            pos = false;
            break;
          }
        }
      }
      // 만약 그룹단어가 아니면 검사 그만
      if(pos == false) continue;
    }
    // 그룹단어일 경우 1 증가
    if(pos) num++;
  }

  cout << num << endl;
}
