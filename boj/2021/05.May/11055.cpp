#include <iostream>

using namespace std;

int N, answer;
int arr[1001];
int ans[1001];

int main(void)
{
    cin >> N;
    for(int i = 1 ; i <= N ; i++) cin >> arr[i];

    for(int i = 1 ; i <= N ; i++)                   // 각 인덱스의 최대 증가 수열 값을 구함
    {
        int maxi = 0;                               // 이번 인덱스값보다 작은 값들 중 최대합
        for(int idx = 1 ; idx < i ; idx++)
        {
            if(arr[idx] < arr[i] && ans[idx] > maxi)    // 증가 부분 수열이 되기 위해, 이번 인덱스값보다 작은 값이어야 함
            {
                maxi = ans[idx];                        // 해당 인덱스들 중 최대합을 갖는 값
            }
        }
        ans[i] = maxi + arr[i];                     // 이번 라운드에 갱신가능한 이전까지의 최댓값 + 현재값
        if(answer < ans[i]) answer = ans[i];        // 최댓값 갱신해줌
    }

    cout << answer << endl;
}