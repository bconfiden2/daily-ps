a  #include <iostream>
using namespace std;

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int dataNum = 0;
    int* datas = NULL;
    int* results = NULL;
    int term = 0;

    cin >> dataNum;
    datas = new int[dataNum];
    for(int j = 0 ; j < dataNum ; j++)
    {
      cin >> datas[j];
    }
    cin >> term;

    int resultNum = dataNum - term + 1;
    results = new int[resultNum];

    cout << resultNum << " ";
    for(int k = 0 ; k < resultNum ; k++)
    {
      results[k] = 0;
      for(int j = 0 ; j < term ; j++)
      {
        results[k] += datas[k + j];
      }
      results[k] /= term;
      cout << results[k] << " ";
    }
    cout << endl;

    delete(datas);
    delete(results);
  }
}
