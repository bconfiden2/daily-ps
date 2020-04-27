#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  string word;
  cin >> word;

  int alp[26] = {0};
  for(int i = 0 ; i < word.length() ; i++)
  {
    //소문자
    if(int(word[i]) >= 97)
    {
      alp[int(word[i] - 97)]++;
    }
    //대문자
    else
    {
      alp[int(word[i] - 65)]++;
    }
  }

  int maxNum = 0;
  int idx = 0;
  int count = 0;
  for(int i = 0 ; i < 26 ; i++)
  {
    if(alp[i] > maxNum)
    {
      maxNum = alp[i];
      idx = i;
    }
  }
  for(int i = 0 ; i < 26 ; i++)
  {
    if(alp[i] == maxNum)
    {
      count++;
    }
  }
  if(count > 1)
  {
    cout << "?" << endl;
  }
  else
  {
    cout << char(65 + idx) << endl;
  }
}
