#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
  if(a.length() == b.length())
  {
    return a < b;
  }
  else
  {
    return a.length() < b.length();
  }
}

int main(void)
{
  int n = 0;
  scanf("%d", &n);
  vector<string> v;

  for(int i = 0 ; i < n ; i++)
  {
    char ax[51];
    scanf("%s", ax);
    string a(ax);
    if(find(v.begin(), v.end(), a) == v.end())
    {
      v.push_back(a);
    }
  }

  sort(v.begin(), v.end(),compare);

  for(int i = 0 ; i < v.size() ; i++)
  {
    printf("%s\n", v[i].c_str());
  }
}
