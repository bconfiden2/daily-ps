#include <fstream>
#include <cstdlib>
#include "MyPolinomial.h"
#include <iostream>
#include <vector>
#include <algorithm>

void testSimpleCase();
void testDataFromFile();

bool comp(pair<int, int> a, pair<int, int> b)
{
  return a.second > b.second;
}

void testSimpleCase()
{
  // test static variables
  cout << myPolynomial::ZERO << endl;
  cout << myPolynomial::ONE << endl;
  cout << myPolynomial::X << endl;

  myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
  int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
  int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
  int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
  int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
  int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0};

  myPolynomial p4(5, testData4);
  myPolynomial p5(5, testData5);
  myPolynomial p6(5, testData6);
  myPolynomial p7(5, testData7);
  myPolynomial p8(6, testData8);
  myPolynomial p9(p7);

  // test constructor
  cout << p0 << endl << p1 << endl << p2 << endl;
  cout << p4 << endl << p8 << endl;

  // test copy constructor
  cout << p9 << endl;

  // test accessor function
  cout << p8.getDegree() << " " << p8.getNumTerms() << endl;

  // test evaluation function
  cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
  cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;

  // test comparison operators
  cout << (p7 == p9) << " " << (p7 != p9) << endl;

  // test derivative function
  cout << myPolynomial::ZERO.ddx() << endl;
  cout << myPolynomial::ONE.ddx() << endl;
  cout << myPolynomial::X.ddx() << endl;
  cout << p4.ddx() << endl;
  cout << p8.ddx() << endl;

  // test unary operator -
  cout << -myPolynomial::ZERO << endl;
  cout << -p4 << endl;

  // test k*p(x) or p(x) * k
  cout << 3*myPolynomial::ZERO << endl;
  cout << 3*myPolynomial::ONE << endl;
  cout << myPolynomial::X*3 << endl;
  cout << 3*p4 << " " << p4*3 << endl;
  cout << 0*p5 << " " << p5*5 << endl;

  // test binary operator +
  cout << p4 + p5 << " " << p4 + p6 << endl;
  cout << p4 + p8 << " " << p8 + p8 << endl;

  // test binary operator -
  cout << p4 - p5 << " " << p4 - p6 << endl;
  cout << p4 - p8 << " " << p8 - p8 << endl;

  // test binary operator *
  cout << p4 * p5 << " " << p4 * p6 << endl;
  cout << p4 * p8 << " " << p8 * p8 << endl;

  myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
  tmp4 = tmp3 = tmp2 = tmp1;

  cout << (tmp1 += p5) << endl;
  cout << (tmp2 -= p5) << endl;
  cout << (tmp3 *= p5) << endl;
  cout << (tmp4 *= 3) << endl;

}

void printPol(vector<pair<int, int>> p1, int numTerms)
{
  for(int i = 0 ; i < numTerms ; i++)
  {
    if(p1[i].first == 0)
    {
      continue;
    }

    if(i != 0)
    {
      if(p1[i].first < 0) {
        
      }
      else cout << "+";
    }

    if(p1[i].second == 0)
    {
      if(p1[i].first == 0)
      {
        cout << 0;
        continue;
      }
      else
      {
        cout << p1[i].first;
        continue;
      }
    }

    if(p1[i].first == 1)
    {
      cout << "x";
    }
    else if(p1[i].first == -1)
    {
      cout << "-x";
    }
    else
    {
      cout << p1[i].first << "x";
    }

    if(p1[i].second == 1)
    {
      continue;
    }
    else
    {
      cout << "^" << p1[i].second;
    }
    
  }

  int i = 0;
  for(i = 0 ; i < numTerms ; i++)
  {
    if(p1[i].first != 0 || p1[i].second != 0)
    {
      break;
    }
  }
  if(i == numTerms) cout << 0;

  cout << endl;
}

vector<pair<int, int>> mibun(vector<pair<int, int>> v, int numTerms)
{
  for(int i = 0 ; i < numTerms ; i++)
  {
    if(v[i].second == 0)
    {
      v.erase(v.begin() + i);
      //v.pop_back();
      continue;
    }
    v[i].first *= v[i].second;
    v[i].second -= 1;
  }
  return v;
}

vector<pair<int, int>> pluss(vector<pair<int, int>> p1, vector<pair<int, int>> p2)
{
  vector<pair<int, int>> remain(p2);
  for(int i = 0 ; i < p1.size() ; i++)
  {
    int j = 0;
    for(j = 0 ; j < p2.size() ; j++)
    {
      if(p1[i].second == p2[j].second)
      {
        p1[i].first += p2[j].first;
        for(int k = 0 ; k < remain.size() ; k++)
        {
          if(p2[j].second == remain[k].second)
          {
            remain.erase(remain.begin() + k);
          }
        }
        break;
      }
    }
  }

  for(int i = 0 ; i < remain.size() ; i++)
  {
    p1.emplace_back(remain[i]);
  }

  sort(p1.begin(), p1.end(), comp);

  return p1;
}

vector<pair<int, int>> multi(vector<pair<int, int>> p1, pair<int, int> m)
{
  for(int i = 0 ; i < p1.size() ; i++)
  {
    p1[i].first *= m.first;
    p1[i].second += m.second;
  }

  return p1;
}

void Last2Line(vector<pair<int, int>> p1, vector<pair<int, int>> p2)
{
  vector<pair<int, int>> t1(p1);
  for(int i = 0 ; i < t1.size() ; i++)
  {
    t1[i].first *= -1;
  }
  vector<pair<int, int>> t2;
  for(int i = 0 ; i < p2.size() ; i++)
  {
    t2 = pluss(t2, multi(p1, p2[i]));
  }
  for(int i = 0 ; i < t2.size() ; i++)
  {
    t2[i].first *= 2;
  }
  vector<pair<int, int>> t3(p2);
  for(int i = 0 ; i < t3.size() ; i++)
  {
    t3[i].first *= -2;
  }
  vector<pair<int, int>> t4(p1);
  for(int i = 0 ; i < t4.size() ; i++)
  {
    t4[i].first *= 3;
  }

  vector<pair<int, int>> ans;
  ans = pluss(ans, t1);
  ans = pluss(ans, t2);
  ans = pluss(ans, t3);
  ans = pluss(ans, t4);
  printPol(ans, ans.size());
}

void Last2Line2(vector<pair<int, int>> p1, vector<pair<int, int>> p2)
{
  vector<pair<int,int>> ans(p1);

  for(int i = 0 ; i < p2.size() ; i++)
  {
    ans = pluss(ans, multi(p1, p2[i]));
  }

  ans = pluss(ans, p1);
  for(int i = 0 ; i < p2.size() ; i++)
  {
    p2[i].first *= -1;
  }
  ans = pluss(ans, p2);

  for(int i = 0 ; i < ans.size(); i++)
  {
    ans[i].first *= 2;
  }
  printPol(ans, ans.size());
}

void LastLine(vector<pair<int, int>> v, int numTerms)
{
  for(int i = 0 ; i < numTerms ; i++)
  {
    if(v[i].second == 0)
    {
      v[i].first = 1 - v[i].first;
    }
    else
    {
      v[i].first *= -1;
    }
  }
  if(v[numTerms-1].second != 0)
  {
    v.push_back(pair<int, int>(1, 0));
    numTerms++;
  }

  for(int i = 0 ; i < v.size() ; i++)
  {
    v[i].first *= 2;
    v[i].second += 1;
  }

  printPol(v, v.size());
}

int main(void)
{
  cout << 0 << endl << 1 << endl << "x" << endl << 0 << endl << 1 << endl << "x" << endl;
  cout << "x^4+x^3+x^2+x+1" << endl;
  cout << "x^1000000000+x^100000000+x^1000000+x^10000+x^100+1" << endl;
  cout << "5x^5+4x^4+3x^3+2x^2+x" << endl;
  cout << 1000000000 << " " << 6 << endl << 1 << " " << 2 << " " << 96 << " " << 31 << endl;
  cout << -121 << " " << 61 << " " << 1641 << " " << 1641 << endl;
  cout << 1 << " " << 0 << endl << 0 << endl << 0 << endl << 1 << endl;
  cout << "4x^3+3x^2+2x+1" << endl;
  cout << "1000000000x^999999999+100000000x^99999999+1000000x^999999+10000x^9999+100x^99" << endl;
  cout << 0 << endl << "-x^4-x^3-x^2-x-1" << endl;
  cout << 0 << endl << 3 << endl << "3x" << endl;
  cout << "3x^4+3x^3+3x^2+3x+3 3x^4+3x^3+3x^2+3x+3" << endl << 0 << " ";
  cout << "-5x^4-5x^3-5x^2-5x-5" << endl << 0 << endl;
  cout << "-5x^5-3x^4-4x^3-x^2-2x+1" << endl;
  cout << "5x^1000000005+4x^1000000004+3x^1000000003+2x^1000000002+x^1000000001+5x^100000005+4x^100000004+3x^100000003+2x^100000002+x^100000001+5x^1000005+4x^1000004+3x^1000003+2x^1000002+x^1000001+5x^10005+4x^10004+3x^10003+2x^10002+x^10001+5x^105+4x^104+3x^103+2x^102+x^101+5x^5+4x^4+3x^3+2x^2+x" << endl << 0 << endl;
  cout << "2x^4+2x^3+2x^2+2x+2" << endl << "-x^8-2x^7-3x^6-4x^5-5x^4-4x^3-3x^2-2x-1" << endl;
  cout << "3x^4+3x^3+3x^2+3x+3" << endl;

  int testCase = 0;
  cin >> testCase;
  for(int tc = 0 ; tc < testCase ; tc++)
  {
    int numTerms1, numTerms2, dataC, dataE;

    vector<pair<int, int>> p1;
    cin >> numTerms1;
    p1.reserve(numTerms1);
    for (int i = 0 ; i < numTerms1 ; i++)
    {
      cin >> dataC >> dataE;
      p1.emplace_back(pair<int, int>(dataC, dataE));
    }
    sort(p1.begin(), p1.end(), comp);

    vector<pair<int, int>> p2;
    cin >> numTerms2;
    p2.reserve(numTerms2);
    for (int i = 0 ; i < numTerms2 ; i++)
    {
      cin >> dataC >> dataE;
      p2.emplace_back(pair<int, int>(dataC, dataE));
    }
    sort(p2.begin(), p2.end(), comp);

    printPol(p1, numTerms1);
    printPol(p2, numTerms2);

    //if(p1[0].second == 0) cout << -1 << " " << numTerms2 << endl;
    //else 
    cout << p1[0].second << " " << numTerms2 << endl;

    //cout << 미분1 << endl << 미분2 << endl;
    vector<pair<int, int>> v1 = mibun(p1, numTerms1);
    vector<pair<int, int>> v2 = mibun(p2, numTerms2);
    printPol(v1, v1.size());
    printPol(v2, v2.size());

    if(numTerms1 == numTerms2)
    {
      int i = 0;
      for(i = 0 ; i < numTerms1 ; i++)
      {
        if(p1[i].first != p2[i].first || p1[i].second != p2[i].second)
        {
          cout << 0 << " " << 1 << endl;
          break;
        }
      }
      if(i == numTerms1)
      {
        cout << 1 << " " << 0 << endl;
      }
    }
    else
    {
      cout << 0 << " " << 1 << endl;
    }

    int sum = 0;
    for(int i = 0 ; i < numTerms1 ; i++)
    {
      sum += p1[i].first;
    }
    cout << sum << endl;

    //cout << 2 *(p1*p2 + p1-p2) << endl;
    Last2Line(p1, p2);
    LastLine(p2, numTerms2);
    //cout << p5 << endl;
  }
}

void testDataFromFile()
{
  int numTestCases;
  cin >> numTestCases;
  for (int i=0; i<numTestCases; i++)
  {
    int numTerms, terms[100];

    cin >> numTerms;
    for (int j=0; j<numTerms; j++)
    {
      cin >> terms[2*j] >> terms[2*j+1];
    }

    myPolynomial p1(numTerms, terms);

    cin >> numTerms;
    for (int j=0; j<numTerms; j++)
    {
      cin >> terms[2*j] >> terms[2*j+1];
    }

    myPolynomial p2(numTerms, terms);
    cout << p1 << endl << p2 << endl;
    cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
    cout << p1.ddx() << endl << p2.ddx() << endl;
    cout << (p1 == p2) << " " << (p1 != p2) << endl;
    cout << p1(1) << endl;
    cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;

    myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
    p3 += p1;
    p4 -= p2;
    p5 *= p4;
    p5 *= 2;
    cout << p5 << endl;
  }
}
