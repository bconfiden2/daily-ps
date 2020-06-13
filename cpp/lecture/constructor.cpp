#include <iostream>

class A
{
public:
    A(int& r, int p = 0, int c = 0) : c(c), r(r)
    {
        this->p = p;
        std::cout << "A() called : " << this->p << " : " << this << std::endl;
    }
    ~A()
    {
        std::cout << "~A() called : " << this << std::endl;
    }

    int getP()
    {
        std::cout << &p << std::endl;
        return p;
    }
    int getR()
    {
        std::cout << &  r << std::endl;
        return r;
    }
    int getC()
    {
        return c;
    }
    void setP(int p)
    {
        this->p = p;
    }
    void setR(int r)
    {
        this->r = r;
    }
private:
    int& r;
    int p;
    const int c;
};

int k2 = 4;
A a2(k2);

int main(void)
{
    int k1 = 5;
    A a1(k1, 6, 7);
    std::cout << a1.getR() << std::endl;
    std::cout << a1.getP() << std::endl;
    std::cout << a1.getC() << std::endl;

    std::cout << a2.getR() << std::endl;
    std::cout << a2.getP() << std::endl;
    std::cout << a2.getC() << std::endl;

    a2.setR(10);
    std::cout << k2 << std::endl;
    a1.setR(20);
    std::cout << k1 << std::endl;
    std::cout << &k1 << std::endl;
    std::cout << a1.getR() << std::endl;

    return 0;
}