#include "MyPolinomial.h"
#include <vector>
#include <algorithm>

bool cmp(pair<int, int> a, pair<int, int> b)
{
  return a.second > b.second;
}

bool cmp2(myTerm a, myTerm b)
{
  return a.getExp() > b.getExp();
}

myPolynomial myPolynomial::ZERO(0, (unsigned)0);              // the zero polynomial P(x) = 0
myPolynomial myPolynomial::ONE(1, (unsigned)0);  // the monomial P(x) = 1
myPolynomial myPolynomial::X(1, (unsigned)1);             // the monomial P(x) = x

myPolynomial::myPolynomial(int c, unsigned int e)
{
  degree = e;
  sen.push_back(myTerm(c, e));
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
  vector<pair<int, int>> v;

  v.reserve(nTerms);
  for(int i = 0 ; i < nTerms ; i++)
  {
    v.emplace_back(pair<int, int>(mono[2 * i], mono[2 * i + 1]));
  }
  sort(v.begin(), v.end());

  for(int i = nTerms - 1 ; i >= 0 ; i--)
  {
    sen.push_back(myTerm(v[i].first, v[i].second));
  }

  degree = v[nTerms - 1].second;
}

myPolynomial::myPolynomial(const myPolynomial& poly) : degree(poly.degree), sen(poly.sen)
{
  /*
  degree = poly.degree;

  for(list<myTerm>::iterator iter = poly.sen.begin() ; iter != poly.sen.end() ; iter++)
  {
    sen.push_back(*iter);
  }
  */
}

myPolynomial::myPolynomial(int deg, list<myTerm> list) : degree(deg), sen(list)
{
  
}

bool myPolynomial::operator==(myPolynomial poly)
{
  if(sen.size() != poly.sen.size()) return false;

  list<myTerm>::iterator iter1 = sen.begin();
  list<myTerm>::iterator iter2 = poly.sen.begin();
  for(int i = 0 ; i < sen.size() ; i++, iter1++, iter2++)
  {
    if(*(iter1) != *(iter2))
    {
      return false;
    }
  }
  return true;
}

bool myPolynomial::operator!=(myPolynomial poly)
{
  return !(*this == poly);
}

myPolynomial myPolynomial::operator-()
{
  myPolynomial temp(*this);

  list<myTerm>::iterator iter = temp.sen.begin();
  for(int i = 0 ; i < temp.sen.size() ; i++, iter++)
  {
    *(iter) = -*(iter);
  }

  return temp;
}

myPolynomial& myPolynomial::operator+=(myPolynomial poly)
{
  return (*this);
}

myPolynomial& myPolynomial::operator-=(myPolynomial poly)
{
  return (*this);
}

myPolynomial& myPolynomial::operator*=(myPolynomial poly)
{
  return (*this);
}

myPolynomial& myPolynomial::operator*=(int k)
{
  return (*this);
}

myPolynomial myPolynomial::operator*(int k)
{
  myPolynomial a(0);

  return a;
}

// friend operators and functions
myPolynomial operator*(int k, myPolynomial poly)
{
  myPolynomial a(0);

  return a;
}

myPolynomial myPolynomial::ddx()
{
  list<myTerm> temp;

  list<myTerm>::iterator iter = sen.begin();
  for(int i = 0 ; i < sen.size() ; i++, iter++)
  {
    temp.push_back((*iter).ddx()); 
  }

  myPolynomial a(0);

  return a;
}

myPolynomial myPolynomial::operator+(myPolynomial poly)
{
  list<myTerm> temp(sen);
  list<myTerm>::iterator iter = poly.sen.begin();

  for(int i = 0 ; i < poly.sen.size() ; i++, iter++)
  {
    int j = 0;
    list<myTerm>::iterator iter2 = temp.begin();
    for(j = 0 ; j < sen.size() ; j++, iter2++)
    {
      if((*iter).getExp() == (*iter2).getExp())
      {
        temp.push_back(myTerm((*iter).getCoeff() + (*iter2).getCoeff(), (*iter).getExp()));
        break;
      }
    }
    if(j == sen.size())
    {
      temp.push_back(myTerm((*iter).getCoeff(), (*iter).getExp()));
    }
    
  }
  sort(temp.begin(), temp.end(), cmp2);

  int deg = temp.front().getExp();
  myPolynomial a(deg, temp);
  return a;
}

myPolynomial myPolynomial::operator-(myPolynomial poly)
{
  list<myTerm> temp(sen);
  list<myTerm>::iterator iter = poly.sen.begin();

  for(int i = 0 ; i < poly.sen.size() ; i++, iter++)
  {
    int j = 0;
    list<myTerm>::iterator iter2 = temp.begin();
    for(j = 0 ; j < sen.size() ; j++, iter2++)
    {
      if((*iter).getExp() == (*iter2).getExp())
      {
        temp.push_back(myTerm((*iter).getCoeff() - (*iter2).getCoeff(), (*iter).getExp()));
        break;
      }
    }
    if(j == sen.size())
    {
      temp.push_back(myTerm(-(*iter).getCoeff(), (*iter).getExp()));
    }
    
  }
  sort(temp.begin(), temp.end(), cmp2);

  int deg = temp.size();
  myPolynomial a(deg, temp);
  return a;
}

myPolynomial myPolynomial::operator*(myPolynomial poly)
{
  myPolynomial a(0);

  return poly;
}

long myPolynomial::operator()(int x)
{
  long ans = 0;

  list<myTerm>::iterator iter = sen.begin();
  for(int i = 0 ; i < sen.size() ; i++, iter++)
  {
    ans += (*iter).calValue(x);
  }

  return ans;
}

int myPolynomial::getDegree() const
{
  return degree;
}
unsigned myPolynomial::getNumTerms() const
{
  return sen.size();
}
void myPolynomial::setCoeff(int c)
{

}

// output operator
ostream& operator<<(ostream& outStream, myPolynomial poly)
{
  if (poly == myPolynomial::ZERO) return outStream << 0;

  list<myTerm>::iterator iter = poly.sen.begin();
  for(int i = 0 ; i < poly.sen.size() ; i++, iter++)
  {
    if(i == poly.sen.size() - 1) outStream << *iter;
    else outStream << *iter << "+";
  }

  return outStream;
}
