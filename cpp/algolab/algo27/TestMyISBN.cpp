#include <iostream>
#include "MyISBN.h"
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
        {
          cout << "1" << endl;
        }
        else
        {
          cout << "0" << endl;
        }
    }

    return 0;
}
