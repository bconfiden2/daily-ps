#include <iostream>
using namespace std;

class A
{
  const int c;
  int &r;

  public :
  A(int x, int c = 0) : c(c), r(x) {} //cout << this << endl; }
  ~A() {}//cout << this << endl;}

  int getR()
  {
    return r;
  }
  int getC()
  {
    return c;
  }
  void setR(int v)
  {
    r = v;
  }
};

  int g;
  A a2(g, 3);

  int main()
  {
    int i = 1500;
    A a1(i, 10);

    cout << a1.getR() << endl;
    a1.setR(-1);
    cout << a1.getR() << endl;
    cout << a2.getR() << endl;
    a2.setR(-2);
    a1.setR(-3);
    a2.setR(-4);
    a2.setR(-5);
    cout << a1.getR() << endl;
    cout << a1.getR() << endl;
    cout << a2.getR() << endl;
    cout << a2.getR() << endl;
    cout << a1.getR() << endl;

    return 0;
  }
