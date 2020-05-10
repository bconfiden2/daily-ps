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
    if(!strcmp(s, "pop"))
    {
      printf("%d\n", v.size() == 0 ? -1 : v.front());
      if(v.size()) v.erase(v.begin());
    }
    else if(!strcmp(s, "size"))
    {
      printf("%lu\n", v.size());
    }
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
    else
    {
      scanf("%d",&pushData);
      v.push_back(pushData);
    }
  }
}
