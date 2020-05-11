#include <cstdio>
#include <deque>
using namespace std;

int main(void)
{
  deque<int> deq;

  int n = 0;
  char pushes[12];
  int pushData;

  scanf("%d", &n);
  while(n--)
  {
    scanf("%s", pushes);
    switch (pushes[0])
    {
      case 's' :
        printf("%lu\n", deq.size());
        break;
      case 'e' :
        printf("%d\n", deq.empty());
        break;
      case 'f' :
        printf("%d\n", deq.empty() ? -1 : deq.front());
        break;
      case 'b' :
        printf("%d\n", deq.empty() ? -1 : deq.back());
        break;
      case 'p' :
        if(pushes[1] == 'u')
        {
          scanf("%d", &pushData);
          if(pushes[5] == 'f')
          {
            deq.push_front(pushData);
          }
          else
          {
            deq.push_back(pushData);
          }
        }
        else
        {
          if(pushes[4] == 'f')
          {
            if(deq.empty())
            {
              printf("%d\n", -1);
            }
            else
            {
              printf("%d\n", deq.front());
              deq.pop_front();
            }
          }
          else
          {
            if(deq.empty())
            {
              printf("%d\n", -1);
            }
            else
            {
              printf("%d\n", deq.back());
              deq.pop_back();
            }
          }
        }
    }
  }
}
