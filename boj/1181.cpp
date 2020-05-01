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
/*
  for(int i = 0 ; i < n ; i++)
  {
    for(int j = i + 1 ; j < n ; j++)
    {
      if(!words[j].length())
      {
        continue;
      }
      if(words[i].length() > words[j].length())
      {
        //cout << words[i] << "," << i << " <-> " << words[j] << "," << j << endl;
        swap(words[i], words[j]);
      }
      else if(words[i].length() == words[j].length())
      {
          if(words[i].compare(words[j]) > 0)
          {
            //cout << words[i] << "," << i << " <-> " << words[j] << "," << j << endl;
            swap(words[i], words[j]);
          }
          else if(words[i].compare(words[j]) == 0)
          {
            //cout << words[j] << "," << j << "clear" << endl;
            words[j].clear();
          }
      }
    }
  }
*/
  for(int i = 0 ; i < v.size() ; i++)
  {
    printf("%s\n", v[i].c_str());
  }
}
