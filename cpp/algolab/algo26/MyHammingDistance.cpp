#include "MyHammingDistance.h"
#include <iostream>

#define XOR(a,b) (a^b)

// constructors
MyBinaryNumber::MyBinaryNumber () :value(0)
{
}
MyBinaryNumber::MyBinaryNumber (unsigned int val) :value(val)
{
}
// accessor functions
unsigned int MyBinaryNumber::getValue () const
{
  return value;
}
// mutator functions
void MyBinaryNumber::setValue (unsigned int val)
{
  value = val;
}
// 어떤 정수의 해밍 무게를 계산하는 함수
int MyBinaryNumber::getHammingWeight(unsigned int target) const
{
  int count = 0;
  for(int i = 0 ; i < 32 ; i++)
  {
    if(target & (1 << i))
    {
      count++;
    }
  }
  return count;
}
// comptue Hamming Distance
int MyBinaryNumber::getHammingDistance(const MyBinaryNumber& bn) const
{
  return getHammingWeight(XOR(value, bn.getValue()));
}
