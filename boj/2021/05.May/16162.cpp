#include <iostream>

using namespace std;

int N, A, D, temp;
int answer;

int main(void)
{
    cin >> N >> A >> D;
    int cur = A;                // 첫 음부터 확인 시작
    for(int i = 0 ; i < N ; i++)
    {
        cin >> temp;
        if(temp == cur)         // 만약 X단 고음을 위한 현재 음계가 맞다면
        {
            cur += D;           // 다음 단의 음계로 재설정
            answer++;
        }
    }
    cout << answer << endl;
}