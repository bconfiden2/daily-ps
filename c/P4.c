#include <stdio.h>

int main(void)
{
  int arr[10] = {0};
  int i = 0;
  int j = 0;
  int temp = 0;

  for(i = 0 ; i < 10 ; i++)
  {
    scanf("%d", &arr[i]);
  }

  for(i = 0 ; i < 10 ; i ++)
  {
    for(j = 0 ; j < 9 - i ; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("%d\n", arr[8] - arr[1]);
}
