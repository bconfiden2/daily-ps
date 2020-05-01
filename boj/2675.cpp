#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  int T = 0;

  cin >> T;

  for(int i = 0 ; i < T ; i++)
  {
    int R = 0;
    string S = "";

    cin >> R >> S;

    //string answer = "";
    int numS = S.length();
    for(int j = 0 ; j < numS ; j++)
    {
      for(int k = 0 ; k < R ; k++)
      {
        cout << S[j];
      }
    }

    cout << endl;
  }
}
