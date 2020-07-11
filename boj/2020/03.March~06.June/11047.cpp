#include <iostream>

using namespace std;

int n, k;
int coins[10];

int main(void)
{
    cin >> n >> k;
    for(int i = n - 1 ; i >= 0 ; i--)   // 내림차순으로 정렬
    {
        cin >> coins[i];
    }
    int number = 0;
    for(int i = 0, cur ; i < n ; i++)   // 큰것부터 빼나감
    {
        cur = coins[i];
        while(k)                        // 목표값까지 뺴는데
        {
            if(k - cur < 0) break;      // 더 뺄 수 없을 때 까지
            k -= cur;                   // 빼주고
            number++;                   // 동전 갯수 1 증가
        }
    }
    cout << number << '\n';
}