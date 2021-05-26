#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> v(N, 0);                // 실제 데이터
    vector<int> answer(N, 0);           // 각 위치별로 가장 긴 감소하는 부분 수열의 길이

    for(int i = 0 ; i < N ; i++)
    {
        cin >> v[i];
    }

    int maxi = 0;
    for(int i = 0 ; i < N ; i++)
    {
        int temp = 1;                   // i 번째 위치의 가장 긴 길이를 담을 값
        for(int j = 0 ; j < i ; j++)    // 자신 이전까지 모든 최대 길이들을 확인
        {
            if(answer[i] < answer[j] + 1 && v[i] < v[j])    // 최대 길이가 갱신될 경우(감소 부분 수열 조건도 만족)
            {
                answer[i] = answer[j] + 1;
                temp = answer[i];
            }
        }
        if(temp > maxi) maxi = temp;    // 이번 값이 전체값들 중 최대길이인지 확인
        answer[i] = temp;               // i 번째 값 업데이트
    }
    cout << maxi << endl;
}