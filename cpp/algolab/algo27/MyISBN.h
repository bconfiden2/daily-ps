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
  bool isCorrectNumber();
private:
  char isbn[max_length+11];
  char country[5 + 1];
  char publisher[7 + 1];
  char book[6 + 1];
  char checkSum;
  bool isSyntaxValid();
  bool isCheckSumValid();
};

#endif // _MY_ISBN_H_
