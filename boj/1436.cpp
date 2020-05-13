#include <cstdio>
#include <string>
using namespace std;
int main(void)
{
  int n = 0;
  scanf("%d", &n);

  int count = 0;
  int answer = 0;
  int val = 666;

  // 666이 들어간 숫자를 1씩 증가하면서 n번 찾는다
  while(count != n)
  {
    // 666이 들어가있는 숫자라면 count 1 증가, 정답 업데이트하기를 반복
    if(to_string(val).find("666") != string::npos)
    {
      count++;
      answer = val++;
    }
  }
  // 끝나면 answer 에 n번째 666이 포함된 문자가 들어있음
  printf("%d\n", answer);
}

int pow10(int digit)
{
  int n = 1;
  for(int i = 0 ; i < digit ; i++)
  {
    n *= 10;
  }
  return n;
}

int digit666(int data, int key, int digi)
{
  int k = key * 6 + pow10(digi);
  if(data/key < 6)
  {
    return data / key;
  }
  else if(data < k)
  {
    return 6;
  }
  else
  {
    if(data < k + key) return 7;
    else if(data < k + key * 2) return 8;
    else return 9;
  }
}

int main2(void)
{
  int n = 0;
  scanf("%d", &n);
  n--;
  int ans = 1000000 * (n / 3439);

  int dig6 = digit666(n % 3439, 271, 3);
  if(dig6 == 6)
  {
    ans += 666000;
    ans += n % 3439 - 271 * 6;
  }
  else
  {
    ans += 100000 * dig6;
    int dig5 = digit666(n % 3439 % 271, 19, 2);
    if(dig5 == 6)
    {
      ans += 66600;
      ans += n % 3439 % 271 - 19 * 6;
    }
    else
    {
      ans += 10000 * dig5;
      int dig4 = digit666(n % 3439 % 271 % 19, 1, 1);
      if(dig4 == 6)
      {
        ans += 6660;
        ans += n % 3439 % 271 % 19 - 6;
      }
      else
      {
        ans += 1000 * dig4 + 666;
      }
    }
  }

  printf("%d\n", ans);
}
