#include <iostream>

#define ull unsigned long long 

using namespace std;

ull mini, maxi;
bool val[1000001];                                      // 에라토스테네스의 체, min 과 max 사이의 값들에 대한 배열
int number;

int main(void)
{
    cin >> mini >> maxi;

    for(ull i = 2, cur, sum ; i * i <= maxi ; i++)      // 에라토스테네스의 체로 1보다 큰 제곱수를 걸러냄
    {
        cur = i * i;                                    // cur 은 현재 반복문의 제곱값
        sum = mini - (mini % cur);                      // 거를 값, 어차피 min 과 max 사이 값들만 확인하므로 min 근처 값부터 확인한다
        while(sum <= maxi)
        {
            if(sum >= mini)
            {
                val[sum - mini] = true;                 // 제곱값의 배수라면 val 의 해당 인덱스에 표시
            }
            sum += cur;
        }
    }
    for(int i = 0 ; i <= maxi - mini ; i++)             // 전체 배열들 중 걸러지지 않은 값들의 갯수를 셈
    {                                                   // 범위는 max - min 값까지
        if(val[i] == false) number++;
    }
    cout << number << endl;
}