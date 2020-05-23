#include <iostream>
using namespace std;

int main(void)
{
  int N, M;
  cin >> N >> M;

  int answer = 0;
  int* cards = new int[N];
  for(int i = 0 ; i < N ; i++)
  {
    cin >> cards[i];
  }
  for(int i = 0 ; i < N - 2 ; i++)
  {
    for(int j = i + 1 ; j < N - 1 ; j++)
    {
      for(int k = j + 1 ; k < N ; k++)
      {
        int temp =cards[i] + cards[j] + cards[k];
        if (temp > answer)
        {
          if(temp <= M)
          {
            answer = temp;
          }
        }
      }
    }
  }

  cout << answer << endl;
  delete cards;
}
