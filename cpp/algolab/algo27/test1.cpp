#ifndef _MY_ISBN_H_
#define _MY_ISBN_H_
const int max_length = 256;
class MyISBN
{
public:
 // constructors
 MyISBN ();
 MyISBN (char isbn_number[]);
 // utility functions
 bool isCorrectNumber() const;
private:
 char isbn[max_length+11];
 bool isSyntaxValid() const;
 bool isCheckSumValid() const;
};
#endif // _MY_ISBN_H_
/////////////////////////////////MyISBN.cpp
#include "cstring"
//#include "MyISBN.h"
// constructors
MyISBN::MyISBN ()
{
isbn[0] = '\0';
}
MyISBN::MyISBN (char isbn_number[])
{
strcpy(isbn, isbn_number);
}
// utility functions
bool MyISBN::isCorrectNumber() const
{
  if (isSyntaxValid() && isCheckSumValid())
    return true;
  else
    return false;
}
// private functions
bool MyISBN::isSyntaxValid() const
{
  int cou =0;
  int count[5];
  for(int i=0; i<strlen(isbn);i++){/////////////////1
    if(isbn[i] == '-'||isbn[i] == '0' || isbn[i] == '1' || isbn[i] == '2' || isbn[i] == '3' || isbn[i] == '4' ||
     isbn[i] == '5' || isbn[i] == '6' || isbn[i] == '7' || isbn[i] == '8' || isbn[i] == '9' || isbn[i] == 'X'){
       if(isbn[i] == '-'){
         count[cou] = i;
         cou++;
       }
     }
     else        return false; /////////////////1
  }
  if (cou != 3)      return false; ////////////////////////2,3
  if (count[0] == 0 || count[0] > 5)
                  return false; ////////////////////////
  else if(count[1]-count[0]-1 >7 || count[2]-count[1]-1 >6)
                  return false;
  else if(count[1]-count[0] == 1 || count[2]-count[1] == 0)
                  return false; ////////////////////////////
  else if(strlen(isbn) - count[2]-1 != 1)
                  return false;
  else             return true;
}
bool MyISBN::isCheckSumValid() const
{
  int emul[9];
  int che = 0;
  int sum = 0;
  for(int i=0; i<20;i++){
    if(isbn[i] == '0' || isbn[i] == '1' || isbn[i] == '2' ||
     isbn[i] == '3' || isbn[i] == '4' ||
     isbn[i] == '5' || isbn[i] == '6' || isbn[i] == '7'
     || isbn[i] == '8' || isbn[i] == '9'){
        emul[che] = (int)isbn[i] -48;
        che++;
    }
    if(che == 9)
    break;
  }
  for(int i = 0; i< 9; i++)
    sum += emul[i] * (10-i);
  sum %= 11;
  sum = 11-sum;
  if(sum==11) sum=0;
  if(sum == 10){
    if(isbn[strlen(isbn)-1] == 'X')
        return true;
    else
        return false;
  }
  else if ((int)isbn[strlen(isbn)-1]-48 == sum)
      return true;
  else
      return false;
}
/////////////////////////////////TestMyISBN.cpp
#include <iostream>
//#include "MyISBN.h"
using namespace std;
int main()
{
 int numTestCases;
 cin >> numTestCases;
 for (int i=0; i<numTestCases; i++)
 {
 char isbn[max_length+1];
 cin >> isbn;
 MyISBN bookNumber(isbn);
 if(bookNumber.isCorrectNumber())
  cout << "1" << endl;
 else
  cout << "0" << endl;
 }
 return 0;
}