#include "MyIpv4Address.h"
#include <iostream>
#include <cstdlib>

// constructors
MyIpv4Address::MyIpv4Address (): addNumber(0)
{
    num2address();
}

MyIpv4Address::MyIpv4Address (unsigned int num) : addNumber(num)
{
    num2address();
}

MyIpv4Address::MyIpv4Address (char add[])
{
    string2address(add);
    address2num();
}

// utility functions
void MyIpv4Address::printAddress() const
{
    std::cout << address[3] << '.' << address[2] << '.' << address[1] << '.' << address[0] << '\n';
}

void MyIpv4Address::printNumber() const
{
    std::cout << addNumber << '\n';
}

// private functions
void MyIpv4Address::num2address()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        address[i] = addNumber % 256;
        addNumber /= 256;
    }
}

void MyIpv4Address::address2num()
{
    addNumber = address2[0] * 256 * 256 * 256 + address2[1] * 256 * 256 + address2[2] * 256 + address2[3];
}

void MyIpv4Address::string2address(char add[])
{
    int a[4];
    int ix = 0;
    int idx = 0;
    int temp = 0;
    while(ix < 4)
    {
      if(add[idx] == '.' || add[idx] == '\0')
      {
        a[ix++] = temp;
        temp = 0;
      }
      else
      {
        temp++;
      }
      idx++;
    }

    int id = 0;
    for(int i = 0 ; i < 4 ; i++)
    {
        address2[i] = 0;
        int digit = 0;
        if(a[i] == 3)
        {
          digit = 100;
        }
        else if(a[i] == 2)
        {
          digit = 10;
        }
        else
        {
          digit = 1;
        }

        for(int j = 0 ; j < a[i] ; j++, digit /= 10)
        {
            address2[i] += (add[id++] - 48) * digit;
        }
        id++;
    }
}
