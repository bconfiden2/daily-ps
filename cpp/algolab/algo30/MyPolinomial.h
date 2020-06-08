#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_
#include <iostream>
#include <list>
#include "MyTerm.h"

using namespace std;
class myPolynomial
{
public:
  myPolynomial(int c = 0, unsigned e = 0);
  myPolynomial(int nTerms, int mono[]);

  // copy constructor
  myPolynomial(const myPolynomial &poly);
  myPolynomial(int deg, list<myTerm> temp);

  // overloaded operators
  bool operator==(myPolynomial poly);
  bool operator!=(myPolynomial poly);
  myPolynomial& operator+=(myPolynomial poly);
  myPolynomial& operator-=(myPolynomial poly);
  myPolynomial& operator*=(myPolynomial poly);
  myPolynomial& operator*=(int k);

  myPolynomial operator-();
  myPolynomial operator*(int k);
  myPolynomial operator+(myPolynomial poly);
  myPolynomial operator-(myPolynomial poly);
  myPolynomial operator*(myPolynomial poly);
  myPolynomial operator*(myTerm term);

  long operator()(int x); // evaluate the polynomial
  int getDegree() const;         // get a degree of the polynomial
  unsigned getNumTerms() const;  // number of terms in the polynomial
  void setCoeff(int c);
  myPolynomial ddx();      // derivative of a polynomial

  // friend operators and functions
  friend myPolynomial operator*(int k, myPolynomial poly);
  friend ostream& operator<<(ostream &outStream, myPolynomial poly);
  static myPolynomial ZERO; // P(x) = 0
  static myPolynomial ONE;  // P(x) = 1
  static myPolynomial X;    // P(x) = x

private:
  int degree; // maximum expnent
  list<myTerm> sen;
/********************* add your code here ********************************/
};
#endif
