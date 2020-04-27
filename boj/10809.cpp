#include <iostream>
#include <string>
using namespace std;
int main(void)
{
  string S = "";
  cin >> S;

  for(int i = 0 ; i < 26 ; i++)
  {
    cout << int(S.find(char(97 + i))) << " ";
  }
  cout << endl;

  /*
  short alphabet[26] = {0};

  for(int i = 0 ; i < 26 ; i++)
  {
    alphabet[i] = -1;
  }

  for(int j = 0 ; j < S.length() ; j++)
  {
    int i = 0;
    for(i = 0 ; i < 26 ; i++)
    {
      if(S[j] == char(97 + i))
      {
        if(alphabet[i] == -1)
        {
          alphabet[i] = j;
        }
        break;
      }
    }
  }

  for(int i = 0 ; i < 26 ; i++)
  {
    cout << *(alphabet + i) << " ";
  }
  cout << endl;
  */
}
