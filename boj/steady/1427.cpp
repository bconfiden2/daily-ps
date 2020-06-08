#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// sort 내림차순 정렬기준 greater<int>() 로 대체 가능
bool cmp(int a, int b)
{ return a > b; }

int main(void)
{
  string a;
  cin >> a;
  vector<int> v;
  // 입력받은 문자열 순서대로 벡터에 넣어줌
  for(int i = 0 ; i < a.length() ; i++)
  {
    v.push_back(a[i] - 48);
  }
  sort(v.begin(), v.end(), cmp);
  for(int i = 0 ; i < v.size() ; i++)
  {
    cout << v[i];
  }
  cout << endl;
}
