#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int main(void)
{
  vector<int> v;

  int n = 0;
  int pushData = 0;
  char s[6];

  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++)
  {
    scanf("%s", s);
    // pop 일 경우 맨 앞 원소 출력 후 삭제해줌
    if(!strcmp(s, "pop"))
    {
      printf("%d\n", v.size() == 0 ? -1 : v.front());
      if(v.size()) v.erase(v.begin());
    }
    // size 일 경우 벡터의 사이즈 출력
    else if(!strcmp(s, "size"))
    {
      printf("%lu\n", v.size());
    }
    // empty 는 벡터의 사이즈 기준으로 판단, empty() 도 있음
    else if(!strcmp(s, "empty"))
    {
      printf("%d\n", v.size() == 0 ? 1 : 0);
    }
    else if(!strcmp(s, "front"))
    {
      printf("%d\n", v.size() == 0 ? -1 : v.front());
    }
    else if(!strcmp(s, "back"))
    {
      printf("%d\n", v.size() == 0 ? -1 : v.back());
    }
    // push 일 경우 정수 하나를 더 입력받아서 벡터의 맨 뒤에 넣어준다
    else
    {
      scanf("%d",&pushData);
      v.push_back(pushData);
    }
  }
}
