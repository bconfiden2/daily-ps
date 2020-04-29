#include <iostream>
using namespace std;

int** makeMatrix(int row, int col)
{
  int** mat1 = new int*[row];
  for(int i = 0 ; i < row ; i++)
  {
    mat1[i] = new int[col];
  }

  for(int i = 0 ; i < row ; i++)
  {
    for(int j = 0 ; j < col ; j++)
    {
      cin >> mat1[i][j];
    }
  }

  return mat1;
}

void delMatrix(int** mat)
{
  for(int i = 0 ; i < sizeof(mat) / sizeof(int*) ; i++)
  {
    delete[] mat[i];
  }
  delete[] mat;
}

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int tc = 0 ; tc < testCases ; tc++)
  {
    int r, s, t;
    cin >> r >> s >> t;

    int** mat1 = makeMatrix(r, s);
    int** mat2 = makeMatrix(s, t);

    for(int i = 0 ; i < r ; i++)
    {
      for(int j = 0 ; j < t ; j++)
      {
        int sum = 0;
        for(int k = 0 ; k < s ; k++)
        {
          sum += mat1[i][k] * mat2[k][j];
        }
        cout << sum << " ";
      }
      cout << endl;
    }

    delMatrix(mat1);
    delMatrix(mat2);
  }
}
