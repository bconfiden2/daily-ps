#ifndef _MY_IPV4_ADDRESS_H_
#define _MY_IPV4_ADDRESS_H_
class MyIpv4Address
{
public:
    // constructors
    MyIpv4Address ();
    MyIpv4Address (unsigned int num);
    MyIpv4Address (char add[]);
    // utility functions
    void printAddress() const;
    void printNumber() const;
private:
    unsigned int addNumber;
    unsigned int address[4];
    unsigned int address2[4];
    void num2address();
    void address2num();
    void string2address(char add[]);
};
#endif // _MY_IPV4_ADDRESS_H_