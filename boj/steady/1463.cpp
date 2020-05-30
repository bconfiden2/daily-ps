#include <iostream>
#include <cmath>

#define MINI(a,b) a < b ? a : b

using namespace std;

int n;
//int minV = 1;
int arr[1000001] = {0, 0, 1, 1,};

int main(void)
{
  cin >> n;

  for(int i = 4 ; i <= n ; i++)
  {
    arr[i] = arr[i-1] + 1;
    /*
    for(int j = i-1 ; j >= i-3 ; j--)
    {
      int k = i - j + arr[j];
      if(k < plus1) plus1 = k;
    }
    */
    if(i % 2 == 0)
    {
      arr[i] = MINI(arr[i/2] + 1, arr[i]);
    }
    if(i % 3 == 0)
    {
      arr[i] = MINI(arr[i/3] + 1, arr[i]);
    }

    //if(arr[i] < minV) minV = arr[i];
  }

/*
  for(int i = 1 ; i <= n ; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
*/
  //arr[idx*3] = arr[idx] + 1;
  //idx *= 3;
/*
  while(twoN < n)
  {
    twoN *= 2;
    max++;
  }

  for(int i = 0 ; i < max ; i++)
  {
    for(int j = 0 ; j < max ; j++)
    {
      if(i + j > max) break;
      cur = pow(2, i) * pow(3, j);
      if(cur > n) break;
      k = n - cur + i + j;
      if(k < ans && k > 0) ans = k;
    }
  }
  if(n == 1) ans = 0;
*/
/*
for(int i = 1 ; i < 20 ; i++)
{
  cout << arr[i] << " ";
}
cout << endl;
*/

  cout << arr[n] << '\n';
}
