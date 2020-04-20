#include <stdio.h>

double Average(int arr[], int length);

int main(void)
{
  int inputData = 1;
  int dataArray[5] = {0};
  int inputCount = 0;
  double average = 0.0;
  int i = 0;

  while(inputCount < 5)
  {
    scanf("%d", &inputData);
    if(inputData == 0)
    {
      break;
    }
    dataArray[inputCount] = inputData;
    inputCount++;
  }

  average = Average(dataArray, inputCount);

  while(dataArray[i] && i < 5)
  {
    printf("%lf ", (double)dataArray[i] - average);
    i++;
  }
  printf("\n");
}

double Average(int arr[], int length)
{
  double average = 0;

  for(int i = 0 ; i < length ; i++)
  {
    average += (int)arr[i];
  }

  return average / length;
}
