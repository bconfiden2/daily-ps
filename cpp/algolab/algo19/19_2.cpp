#include <iostream>
using namespace std;
typedef unsigned int MYINT;

int main(void)
{
  int counter = 12;

  MYINT hamming[1351] = {1,2,3,4,5,6,8,9,10,12,15,16,};

  while(counter <= 1350)
  {
    int startIdx = 0;

    for(int i = 0 ; i < counter ; i++)
    {
      if(hamming[i] > hamming[counter - 1] / 5)
      {
        startIdx = i;
        break;
      }
    }

    MYINT curHamming = hamming[counter - 1];
    MYINT nextSmall = curHamming * 2;

    for(int i = startIdx ; i < counter ; i++)
    {
      if(curHamming < hamming[i] * 2 && hamming[i] * 2 < nextSmall)
      {
        nextSmall = hamming[i] * 2;
        continue;
      }
      if(curHamming < hamming[i] * 3 && hamming[i] * 3 < nextSmall)
      {
        nextSmall = hamming[i] * 3;
        continue;
      }
      if(curHamming < hamming[i] * 5 && hamming[i] * 5 < nextSmall)
      {
        nextSmall = hamming[i] * 5;
        continue;
      }
    }

    hamming[counter++] = nextSmall;
  }

  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int num = 0;
    cin >> num;
    cout << hamming[num - 1] << endl;
  }
  return 0;
}
