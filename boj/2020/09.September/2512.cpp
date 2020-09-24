#include <iostream>
#include <algorithm>

using namespace std;

int n;
int bud[10000];
unsigned long long m, answer;

int main(void)
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> bud[i];
        answer += bud[i];
    }
    cin >> m;
    sort(bud, bud + n);                 // 예산들 정렬
    if(answer <= m)                     // 모든 요청이 배정될 수 있는 경우에는
    {
        cout << bud[n-1] << endl;       // 요청한 금액 그대로 배정하고 최대예산 출력
        return 0;
    }

    int low = 0, high = bud[n-1];       // 최솟값은 0, 최댓값은 최대예산으로 시작
                                        // 최솟값을 최소예산으로 시작할 경우 논리적 오류 발생 가능
    while(low <= high)
    {
        int mid = (low + high) / 2;     // mid 를 상한액으로 잡고
        unsigned long long total = 0;
        for(int i = 0 ; i < n ; i++)    // 예산을 집행했을 때
        {
            if(bud[i] < mid) total += bud[i];
            else total += mid;
        }
        if(total <= m)                  // 집행이 가능한 경우라면
        {
            answer = mid;               // 답을 갱신시켜주고
            low = mid + 1;              // 위쪽 이분탐색 실시
        }
        else                            // 불가능한 경우라면
        {
            high = mid - 1;             // 아래쪽 이분탐색 실시
        }
    }

    cout << answer << endl;
}