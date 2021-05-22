#include <iostream>

#define ull unsigned long long
#define MOD 1000000007

using namespace std;

ull cur[4] = {0, 1, 1, 1}, mul[4] = {0, 1, 1, 1};

void matmul(ull (&a)[4], ull (&b)[4], ull (&res)[4])    // a, b 는 곱할 행렬, res 는 결과값 담아줄 행렬
{
    ull temp[4];
    temp[0] = ((a[0]*b[0])%MOD + (a[1]*b[2])%MOD)%MOD;  // 행렬곱, 모듈러 연산 적용
    temp[1] = ((a[0]*b[1])%MOD + (a[1]*b[3])%MOD)%MOD;
    temp[2] = ((a[2]*b[0])%MOD + (a[3]*b[2])%MOD)%MOD;
    temp[3] = ((a[2]*b[1])%MOD + (a[3]*b[3])%MOD)%MOD;
    for(int i = 0 ; i < 4 ; i++) res[i] = temp[i];      // 행렬곱 결과를 갱신해줌
}

ull fibonacci(ull n)
{
    ull digit = 1;
    while(n >= digit)
    {
        if(n & digit) matmul(cur, mul, cur);            // 만약 자릿수 겹치면 현재행렬에 제곱행렬 곱해줌
        matmul(mul, mul, mul);                          // 제곱행렬은 매 자릿수마다 제곱됨
        digit = digit << 1;
    }
    return cur[1];
}

int main(void)
{
    ull n;
    cin >> n;
    cout << fibonacci(n-1) << endl;
}
