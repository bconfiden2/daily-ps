#ifndef _MY_HAMMING_DISTANCE_H_
#define _MY_HAMMING_DISTANCE_H_

class MyBinaryNumber
{
public:
// constructors
  MyBinaryNumber ();
  MyBinaryNumber (unsigned int val);
// accessor/mutator functions
  unsigned int getValue() const;
  void setValue(unsigned int val);
// utility function
  int getHammingWeight(unsigned int target) const;
  int getHammingDistance(const MyBinaryNumber& bn) const;

private:
  unsigned int value;
};
#endif // _MY_HAMMING_DISTANCE_H_
