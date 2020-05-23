#include <iostream>
#include <cstring>
using namespace std;

int jogun[4] = {5, 6, 7, 1};

bool isValid(char* line)
{
  // 0~4 각각 국가, 출판사, 책, 체크썸
  char* cuts[4];
  // 각각의 길이
  int cutsLength[4];
  // 입력된 문자열을 각각 잘라냄
  cuts[0] = strtok(line, "-");
  cutsLength[0] = strlen(cuts[0]);
  for(int i = 1 ; i < 4 ; i++)
  {
    cuts[i] = strtok(NULL, "-");
    cutsLength[i] = strlen(cuts[i]);
    // 널값일떄
    if(!cuts[i]) return false;
  }
  // 만약 뒤에 더 들어있을 때
  if(strtok(NULL, "-")) return false;

  for(int i = 0 ; i < 4 ; i++)
  {
    // 비어있을때
    if(cutsLength[i] == 0) return false;
    // 번호 갯수가 조건보다 클 때
    if(cutsLength[i] > jogun[i]) return false;
    // 각 문자가 숫자가 아닐 경우
    for(int j = 0 ; j < cutsLength[i] ; j++)
    {
      if(cuts[i][j] < 48 || cuts[i][j] > 57)
      {
        // 단 체크썸의 경우에는 X 값은 허용
        if(i == 3 && cuts[i][j] == 88) continue;
        return false;
      }
    }
  }


  for(int i = 0 ; i < 4 ; i++)
  {
    cout << cuts[i] << " : " << strlen(cuts[i]) << endl;
  }

  return true;

/*
  char* country = strtok(line, "-");
  char* publisher = strtok(NULL, "-");
  char* book = strtok(NULL, "-");
  char* checkSum = strtok(NULL, "-");
  if(strtok(NULL, "-"))
  {
    return false;
  }

  cout << country << ":" << strlen(country) << endl;
  cout << publisher << ":" << strlen(publisher) << endl;
  cout << book << ":" << strlen(book) << endl;
  cout << checkSum << endl;

  return true;
*/
}


int main(void)
{
  int testCases = 0;
  cin >> testCases;
  for(int tc = 0 ; tc < testCases ; tc++)
  {
    char line[129] = {'\0',};
    cin >> line;
    cout << isValid(line) << endl;
  }
}
