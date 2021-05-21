#include <iostream>

using namespace std;

int N;
int values[8];      // 입력 값들
int answer[8];      // N 개 순서를 바꿔가며 뽑아줄 배열
bool visit[8];      // 뽑을 때 중복되지 않게 관리해주는 배열
int maxi = 0;

void select_next(int depth)
{
    if(depth == N)                          // N 개를 다 뽑았다면
    {
        int temp = 0;
        for(int i = 0 ; i < N-1 ; i++)      // 수식에 맞는 값 구하고
        {
            temp += abs(answer[i] - answer[i+1]);
        }
        if(temp > maxi) maxi = temp;        // 최댓값 갱신
        return;
    }

    for(int i = 0 ; i < N ; i++)            // 이번 자릿수의 값 선택
    {
        if(visit[i]) continue;              // 앞에서 뽑힌 값이라면 넘어감
        visit[i] = true;
        answer[depth] = values[i];          // 이번 자릿수에서 값 넣어주고
        select_next(depth + 1);             // 다음 자릿수의 값 선택
        visit[i] = false;
    }
}

int main(void)
{
    cin >> N;
    for(int i = 0 ; i < N ; i++) cin >> values[i];
    select_next(0);
    cout << maxi << endl;
}