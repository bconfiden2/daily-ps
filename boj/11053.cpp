#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int n = 0;
  cin >> n;
  vector<int> v;

  for(int i = 0 ; i < n ; i++)
  {
    int val = 0;
    cin >> val;
    if(find(v.begin(), v.end(), val) == v.end())
    {
      v.push_back(val);
    }
  }
  //v.erase(unique(v.begin(), v.end()), v.end());
  sort(v.begin(), v.end());

  cout << v.size() << endl;
}
