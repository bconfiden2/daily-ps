#include <iostream>
using namespace std;

struct Integer
{
  int data;
  int freq;
};

int main(void)
{
  int testCaess = 0;
  cin >> testCaess;

  for(int tc = 0 ; tc < testCaess ; tc++)
  {
    int integerNum = 0;
    cin >> integerNum;

    Integer* integers = (Integer*)malloc(sizeof(Integer) * integerNum);

    int curFrequentCount = 0;
    int receievedDataNum = 0;

    for(int i = 0 ; i < integerNum ; i++)
    {
      int data = 0;
      cin >> data;

      bool isInArray = false;

      for(int j = 0 ; j < receievedDataNum ; j++)
      {
        if(integers[j].data == data)
        {
          integers[j].freq++;
          isInArray = true;
        }
        if(integers[j].freq > curFrequentCount)
        {
          curFrequentCount = integers[j].freq;
        }
      }

      if(!isInArray)
      {
        integers[i].data = data;
        integers[i].freq = 1;
        receievedDataNum++;
      }
    }

    int howManyNum = 0;

    for(int i = 0 ; i < integerNum ; i++)
    {
      if(integers[i].freq == curFrequentCount)
      {
        howManyNum++;
      }
    }

    int* sortedIntegers = (int*)malloc(sizeof(int) * howManyNum);
    for(int i = 0 ; i < integerNum ; i++)
    {
      if(integers[i].freq == curFrequentCount)
      {
        howManyNum++;
      }
    }


    cout << howManyNum << " " << curFrequentCount << " ";
    for(int i = 0 ; i < howManyNum ; i++)
    {
      cout << sortedIntegers[i] << " ";
    }
    cout << endl;

    free(integers);
  }
}
