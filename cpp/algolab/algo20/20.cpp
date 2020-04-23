#include <iostream>
using namespace std;

void pushLines(unsigned int line[])
{
  int num;
  cin >> num;
  for(int j = 0 ; j < num ; j++)
  {
    int data = 0;
    cin >> data;
    line[data / 32] = line[data / 32] | (1 << data % 32);
  }
}

void sortArray(int length, int arr[])
{
  for(int i = 0 ; i < length ; i++)
  {
    for(int j = 1 ; j < length ; j++)
    {
      if(arr[j] < arr[j-1])
      {
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
    }
  }
}

void printArray(int count, int arr[])
{
  cout << count << " ";
  for(int i = 0 ; i < count ; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void bit2int(unsigned int data[])
{
  int counter = 0;
  int intArray[133] = {0};

  for(int i = 0 ; i < 5 ; i++)
  {
    for(int j = 0 ; j < 32 ; j++)
    {
      //int val = 1 << j;
      if((data[i] & (1 << j)) != 0)
      {
        intArray[counter] = i * 32 + j;
        counter++;
      }
    }
  }
  sortArray(counter, intArray);

  printArray(counter, intArray);
}



int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    unsigned int line1[5] = {0};
    unsigned int line2[5] = {0};

    pushLines(line1);
    pushLines(line2);

    unsigned int kyo[5], hap[5], cha[5];
    for(int j = 0 ; j < 5 ; j++)
    {
      int test = 0;
      kyo[j] = line1[j] & line2[j];
      hap[j] = line1[j] | line2[j];
      cha[j] = line1[j] ^ kyo[j];
    }

    bit2int(kyo);
    bit2int(hap);
    bit2int(cha);
  }
}
