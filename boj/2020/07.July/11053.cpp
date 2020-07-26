#include <iostream>

using namespace std;

int n;
int arr[1000];      // 입력받은 데이터
int ans[1000];      // 각 인덱스에 대한 최대 길이값을 담을 DP 배열

int main(void)
{
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    int answer = 0;
    for(int i = 0 ; i < n ; i++)                        // DP 배열 채움
    {
        int max = 0;
        for(int idx = 0 ; idx < i ; idx++)              // 이전까지의 배열들을 탐색
        {
            if(arr[idx] < arr[i] && ans[idx] > max)     // 자신보다 작은 입력값들 중, 최대 길이값을 찾음
            {
                max = ans[idx];
            }
        }
        ans[i] = max + 1;                               // 해당 길이값에 자기 자신을 추가하여 길이값 저장
        if(answer < ans[i]) answer = ans[i];            // 전체 길이값들 중 최댓값 갱신
    }

    cout << answer << endl;
}