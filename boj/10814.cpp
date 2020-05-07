#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Member
{
  int age;
  int order;
  char name[101];
} member;

bool compare(Member a, Member b)
{
  return a.age < b.age;
}

int main(void)
{
  int n = 0;
  cin >> n;

  vector<Member> v;

  for(int i = 0 ; i < n ; i++)
  {
    Member t;
    scanf("%d %s", &t.age, t.name);
    v.push_back(t);
  }

  stable_sort(v.begin(), v.end(), compare);

  for(int i = 0 ; i < n ; i++)
  {
    printf("%d %s\n", v[i].age, v[i].name);
  }
}
