#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 0;
  cin >> n;

  vector<pair<int,int>> v;
  // 일단 다 넣어준다
  for(int i = 0 ; i < n ; i++)
  {
    int x, y;
    cin >> x >> y;
    v.emplace_back(pair<int,int>(x,y));
  }
  // 각자 자신의 등수를 검사해서 출력
  for(int i = 0 ; i < n ; i++)
  {
    int rank = 1;
    // 자신보다 덩치가 큰 사람이 있으면 등수를 하나씩 올려줌
    for(int j = 0 ; j < n ; j++)
    {
      if((v[i].first < v[j].first) && (v[i].second < v[j].second))
      {
        rank++;
      }
    }

    cout << rank << " ";
  }
}
/*
  vector<pair<pair<int,int>, int>> v;

  //int rank = 0;
  //int curRank = 1;

  while(n--)
  {
    int rank = 0;
    int x, y;
    cin >> x >> y;

    pair<int,int> dp = make_pair(x, y);
    pair<pair<int,int>, int> p = make_pair(dp, rank);

    for(int i = 0 ; i < v.size() ; i++)
    {
      if(x <= v[i].first.first)
      {
        if(y <= v[i].first.second)
        {

        }
        else
        {
          p.second = v[i].second;
        }
      }
      else
      {
        if(y > v[i].first.second)
        {
          rank++;
        }
        else
        {
          p.second = v[i].second;
        }
      }
      v[i].first = data
      v[i].second = rank;
    }

    v.push_back(p);
  }
}
*/

/*
  vector<pair<int, int>> v;
  while(n--)
  {
    int x, y;
    cin >> x >> y;
    v.emplace_back(pair<int, int>(x, y));
  }

  vector<pair<int,int>> ori(v);

  sort(v.begin(), v.end(), descend);

  int rank = 1;
  int curRank = rank;

  for(int i = 0 ; i < n ; i++)
  {

  }

  for(int i = 0 ; i < v.size() ; i++)
  {
    if(oir[i].first)
    cout << v[i].first << " " << v[i].second << '\n';
  }

  vector<pair<int,int>>::iterator iter;
  for(iter = v.begin() ; iter != v.end() ; iter++)
  {
    cout << iter->first << " " << iter->second << '\n';
  }
*/
