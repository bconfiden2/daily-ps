#include <iostream>
using namespace std;

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int tc = 0 ; tc < testCases ; tc++)
  {
    int studentNum = 0;
    cin >> studentNum;

    int scoreBoard[101] = {0};

    for(int i = 0 ; i < studentNum ; i++)
    {
      int score = 0;
      cin >> score;

      scoreBoard[score]++;
    }

    for(int i = 0 ; i < 101 ; i++)
    {
      if(scoreBoard[i] != 0)
      {
        cout << i << " " << scoreBoard[i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
