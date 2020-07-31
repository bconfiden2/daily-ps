#include <iostream>

#define ull unsigned long long
#define pow(x) ((x) * (x))

ull a, b, c; 

ull mod(ull s)                  // 분할 정복
{
    if(s == 1)  return a % c;   // 1일 경우는 종료
    else        return ((pow(mod(s / 2) % c) % c) * (s % 2 == 0 ? 1 : (a % c))) % c;
}                               // 그 외에는 제곱수를 반으로 나눠서 곱해줌
                                // ex a^91 -> a^45 * a^45 * a
                                // ex a^80 -> a^40 * a^40

int main(void)
{
    std::cin >> a >> b >> c;
    std::cout << mod(b) << '\n';
}