#include "MyTerm.h"
#include <cmath>
// Constructor
myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e)
{

}

// copy constructor
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp)
{

}

// overloaded operators
bool myTerm::operator==(const myTerm& term) const
{
  return (coeff == term.coeff && exp == term.exp);
}

// overloaded operators
bool myTerm::operator!=(const myTerm& term) const
{
  return !(*this==term);
}

// overloaded operators
bool myTerm::operator<(const myTerm& term) const
{
  return exp > term.exp;
}

myTerm myTerm::operator-() const
{
  return myTerm(-coeff, exp);
}

// derivative of a term
myTerm myTerm::ddx() const
{
  if (exp == 0)
  {
    return myTerm(0, 0);
  }
  return myTerm(exp*coeff, exp-1);
}

long myTerm::calValue(int value)
{
  return coeff * (long)pow(value, exp);
}


// output operator
ostream& operator<<(ostream &outStream, const myTerm& term)
{
  if (term.exp == 0)
  {
    if (term.coeff == 0)
    {
      return outStream;
    }
    else
    {
      return outStream << term.coeff;
    }
  }
  // nothing to output
  if (term.coeff == 1)
  {
    outStream << "x";
  }
  else if (term.coeff == -1)
  {
    outStream << "-x";
  }
  else
  {
    outStream << term.coeff << "x";
  }

  if(term.exp == 1)
  {
    return outStream;
  }
  else
  {
    return outStream << "^" << term.exp;
  }
}
