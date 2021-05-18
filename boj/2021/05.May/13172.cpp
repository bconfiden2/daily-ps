#include <iostream>
#define X 1000000007
#define ull unsigned long long

using namespace std;

ull answer, X_ = X-2;
ull M, N, S;

ull reverse(ull N)                          // N 의 모듈러 곱셉에 대한 역원 구하기
{                                           // N^(X-2) 값을 모듈러 X 로 나눈 값
    ull b = 1, digit = 1, temp = N;

    while(digit <= X_)                      // X-2 제곱을 분할하여 곱함
    {
        if(digit & X_) b = (b * temp) % X;  // 비트가 1인 자릿수에서는 b 에 temp 를 곱해줌
        temp = (temp * temp) % X;           // temp 는 계속 제곱해줌으로써 값 유지
        digit = digit << 1;
    }

    return b;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    for(int i = 0 ; i < M ; i++)
    {
        cin >> N >> S;                                  // 문제의 조건에 의해, 기약분수를 구하지 않고
        answer = (answer + (S * reverse(N)) % X) % X;   // 각 모듈러값들을 모듈러 더하기로 구해줌
    }

    cout << answer << endl;
}