#include <iostream>
using namespace std;

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int row = 0;
    int col = 0;
    cin >> row >> col;

    int* mat1 = new int[row * col];
    int* mat2 = new int[row * col];

    for(int idxR = 0 ; idxR < row ; idxR++)
    {
      for(int idxC = 0 ; idxC < col ; idxC++)
      {
        cin >> mat1[idxR * col + idxC];
      }
    }
    for(int idxR = 0 ; idxR < row ; idxR++)
    {
      for(int idxC = 0 ; idxC < col ; idxC++)
      {
        cin >> mat2[idxR * col + idxC];
      }
    }
    for(int idxR = 0 ; idxR < row ; idxR++)
    {
      for(int idxC = 0 ; idxC < col ; idxC++)
      {
        cout << mat1[idxR * col + idxC] + mat2[idxR * col + idxC] << " ";
      }
      cout << endl;
    }

    delete[] mat1;
    delete[] mat2;
  }
}
