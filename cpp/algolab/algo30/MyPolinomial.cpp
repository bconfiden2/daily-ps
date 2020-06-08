#include "MyPolinomial.h"
#include <vector>
#include <algorithm>

bool cmp(pair<int, int> a, pair<int, int> b)
{
  return a.second > b.second;
}
/*
bool cmp2(const myTerm a, const myTerm b)
{
  return a < b;
}
*/
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

myPolynomial::myPolynomial(int deg, list<myTerm> temp) : degree(deg), sen(temp)
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
  list<myTerm>::iterator iter2 = sen.begin();
  for(int i = 0 ; i < temp.sen.size() ; i++, iter++, iter2++)
  {
    *iter = -(*iter2);
  }

  return temp;
}

myPolynomial& myPolynomial::operator+=(myPolynomial poly)
{
  list<myTerm>::iterator iter = poly.sen.begin();

  for(int i = 0 ; i < poly.sen.size() ; i++, iter++)
  {
    int j = 0;
    list<myTerm>::iterator iter2 = sen.begin();
    for(j = 0 ; j < sen.size() ; j++, iter2++)
    {
      if((*iter).getExp() == (*iter2).getExp())
      {
        (*iter2).setCoeff((*iter).getCoeff() + (*iter2).getCoeff());
        //sen.push_back(myTerm((*iter).getCoeff() + (*iter2).getCoeff(), (*iter).getExp()));
        break;
      }
    }
    if(j == sen.size())
    {
      iter2 = sen.begin();
      for(int k = 0 ; k < sen.size() ; k++, iter2++)
      {
        if((*iter2).getExp() < (*iter).getExp())
        {
          sen.insert(iter2, *iter);
          break;
          //sen.push_back(myTerm((*iter).getCoeff(), (*iter).getExp()));
        }
      }
    }
    
  }
  //sort(sen.begin(), sen.end(), cmp2);

  degree = sen.front().getExp();
  return (*this);
}

myPolynomial& myPolynomial::operator-=(myPolynomial poly)
{
  list<myTerm>::iterator iter = poly.sen.begin();

  for(int i = 0 ; i < poly.sen.size() ; i++, iter++)
  {
    int j = 0;
    list<myTerm>::iterator iter2 = sen.begin();
    for(j = 0 ; j < sen.size() ; j++, iter2++)
    {
      if((*iter).getExp() == (*iter2).getExp())
      {
        (*iter2).setCoeff((*iter).getCoeff() - (*iter2).getCoeff());
        //sen.push_back(myTerm((*iter).getCoeff() + (*iter2).getCoeff(), (*iter).getExp()));
        break;
      }
    }
    if(j == sen.size())
    {
      iter2 = sen.begin();
      for(int k = 0 ; k < sen.size() ; k++, iter2++)
      {
        if((*iter2).getExp() < (*iter).getExp())
        {
          sen.insert(iter2, *iter);
          break;
          //sen.push_back(myTerm((*iter).getCoeff(), (*iter).getExp()));
        }
      }
    }
    //if(j == sen.size())
    //{
    //  sen.push_back(myTerm(-(*iter).getCoeff(), (*iter).getExp()));
    //}
    
  }
  //sort(sen.begin(), sen.end(), cmp2);

  degree = sen.front().getExp();

  return (*this);
}

myPolynomial myPolynomial::operator*(myTerm term)
{
  myPolynomial temp(*this);

  list<myTerm>::iterator iter = temp.sen.begin();

  for(int i = 0 ; i < temp.sen.size() ; i++, iter++)
  {
    (*iter).setCoeff((*iter).getCoeff() * term.getCoeff());
    (*iter).setExp((*iter).getExp() + term.getExp());
  }

  return temp;
}

myPolynomial& myPolynomial::operator*=(myPolynomial poly)
{
  myPolynomial res(*this);

  sen.clear();

  list<myTerm>::iterator iter = poly.sen.begin();
  for(int i = 0 ; i < poly.sen.size() ; i++, iter++)
  {
    (*this) += res * (*iter);
  }

  return (*this);
}

myPolynomial& myPolynomial::operator*=(int k)
{
  list<myTerm>::iterator iter = sen.begin();
  
  for(int i = 0 ; i < sen.size() ; i++, iter++)
  {
    (*iter).setCoeff((*iter).getCoeff() * k);
  }

  return (*this);
}

myPolynomial myPolynomial::operator*(int k)
{
  myPolynomial a(*this);

  a *= k;

  return a;
}

// friend operators and functions
myPolynomial operator*(int k, myPolynomial poly)
{
  return poly * k;
}

myPolynomial myPolynomial::operator*(myPolynomial poly)
{
  poly *= (*this);
  return poly;
}

myPolynomial myPolynomial::ddx()
{
  list<myTerm> temp;

  list<myTerm>::iterator iter = sen.begin();
  for(int i = 0 ; i < sen.size() ; i++, iter++)
  {
    temp.push_back((*iter).ddx()); 
  }

  myPolynomial a(degree-1, temp);

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
      iter2 = sen.begin();
      for(int k = 0 ; k < sen.size() ; k++, iter2++)
      {
        if((*iter2).getExp() < (*iter).getExp())
        {
          sen.insert(iter2, *iter);
          break;
          //sen.push_back(myTerm((*iter).getCoeff(), (*iter).getExp()));
        }
      }
    }
    //if(j == sen.size())
    //{
    //  temp.push_back(myTerm((*iter).getCoeff(), (*iter).getExp()));
    //}
    
  }
  //sort(temp.begin(), temp.end(), cmp2);

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
      iter2 = sen.begin();
      for(int k = 0 ; k < sen.size() ; k++, iter2++)
      {
        if((*iter2).getExp() < (*iter).getExp())
        {
          sen.insert(iter2, *iter);
          break;
          //sen.push_back(myTerm((*iter).getCoeff(), (*iter).getExp()));
        }
      }
    }
    //if(j == sen.size())
    //{
    //  temp.push_back(myTerm(-(*iter).getCoeff(), (*iter).getExp()));
    //}
    
  }
  //sort(temp.begin(), temp.end(), cmp2);

  int deg = temp.size();
  myPolynomial a(deg, temp);
  return a;
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
    else if((*iter).getCoeff() < 0)
    {
      outStream << *iter;
    }
    else outStream << *iter << "+";
  }

  return outStream;
}
