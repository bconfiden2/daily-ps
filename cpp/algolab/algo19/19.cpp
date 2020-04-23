#include <iostream>
using namespace std;
typedef unsigned int MYINT;


bool inputHamming(MYINT hamming[], int counter, int num, int i)
{
  bool figure = false;
  for(int j = 0 ; j < counter ; j++)
  {
    if(hamming[j] == hamming[i] * num)
    {
      figure = true;
      break;
    }
  }

  return figure;
}

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  MYINT hamming[1350] = {1,};

  int counter = 1;

  for(int i = 0 ; i < 1350 ; i ++)
  {
    if(!inputHamming(hamming, counter, 2, i))
    {
      hamming[counter++] = hamming[i] * 2;
      if(counter >= 1350) break;
    }
    if(!inputHamming(hamming, counter, 3, i))
    {
      hamming[counter++] = hamming[i] * 3;
      if(counter >= 1350) break;
    }
    if(!inputHamming(hamming, counter, 5, i))
    {
      hamming[counter++] = hamming[i] * 5;
      if(counter >= 1350) break;
    }
  }

  for(int i = 0 ; i < 1350 ; i++)
  {
    for(int j = 1; j < 1350 ; j++)
    {
      if(hamming[j - 1] > hamming[j])
      {
        MYINT temp = hamming[j];
        hamming[j] = hamming[j-1];
        hamming[j-1] = temp;
      }
    }
    cout << i << "\t" << hamming[i] << endl;
  }

  /*
  for(int i = 0 ; i < testCases ; i ++)
  {
    int k = 0;
    cin >> k;
    cout << hamming[i - 1] << endl;
  }
  */
}
