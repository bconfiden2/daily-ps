#include <iostream>
using namespace std;

class Kvector
{
private:
    int *m;
    int len;
public:
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector& v);
    ~Kvector();

    void print() const;
    void clear();
    int size() const;

    friend void printVec(const Kvector& v);
};

Kvector::Kvector(int sz, int value)
{
    cout << this << " : Kvector(int, int)" << endl;
    len = sz;
    m = nullptr;
    if(sz != 0)
    {
        m = new int[sz];
        for(int i = 0 ; i < sz ; i++)
        {
            m[i] = value;
        }
    }
}
Kvector::Kvector(const Kvector& v)
{
    cout << this << " : Kvector(Kvector&)" << endl;
    len = v.size();
    m = new int[len];
    for(int i = 0 ; i < len ; i++)
    {
        m[i] = v.m[i];
    }
}
Kvector::~Kvector()
{
    cout << this << endl;
    delete[] m;
}
void Kvector::print() const
{
    for(int i = 0 ; i < len ; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}
void Kvector::clear()
{
    delete[] m;
    m = nullptr;
    len = 0;
}
int Kvector::size() const
{
    return len;
}

void printVec(const Kvector& v)
{
    v.print();
}


int main(void)
{
    Kvector v1(3); v1.print();
    Kvector v2(2, 9); v2.print();
    Kvector v3(v2); v3.print();

    //v2.clear();
    v2.print();
    v3.print();

    return 0;  
}