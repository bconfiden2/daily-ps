#ifndef _MY_HAMMING_CODE_H_
#define _MY_HAMMING_CODE_H_
class MyHammingCode
{
public:
// constructors
  MyHammingCode ();
  MyHammingCode (unsigned int val);
// accessor/mutator functions
  unsigned int getEncodedValue();
  unsigned int getDecodedValue();

private:
  unsigned int value;
  unsigned int encodedValue;
  unsigned int decodedValue;

  unsigned int copyBits(unsigned int n, int from, int num, int to);
  unsigned int setParityBit(unsigned int n, int pos);
  unsigned int power(int a, int n);
  unsigned int checkParityBit(unsigned int n);
  int hammingWeight(unsigned int n);
  unsigned int setBit(unsigned int n, int pos);
  unsigned int clearBit(unsigned int n, int pos);
  int checkBit(unsigned int n, int pos);
  unsigned int negateBit(unsigned int n, int pos);
  unsigned int _xor(unsigned int x, unsigned int y);
};
#endif // _MY_HAMMING_CODE_H_
