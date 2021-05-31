#include <iostream>

using namespace std;

int N, temp, answer = 0;
int honey[100000];
int leftc[100000];          // 인덱스 0 부터 i 까지 누적합
int rightc[100000];         // 인덱스 N-1 부터 i 까지 누적합

int main(void)
{
    cin >> N;

    for(int i = 0 ; i < N ; i++)
    {
        cin >> honey[i];
        temp += honey[i];
        leftc[i] = temp;
    }
    for(int i = 0 ; i < N ; i++)
    {
        rightc[i] = temp;
        temp -= honey[i];
    }

    temp = 0;
    for(int i = 1 ; i < N-1 ; i++)  // 통이 가장 오른쪽, 꿀벌 하나는 가장 왼쪽 고정이고 나머지 꿀벌의 위치
    {
        if(leftc[N-1] - leftc[i] - honey[i] > temp)     // 나머지 꿀벌 하나가 갖는 최댓값 확인
        {
            temp = leftc[N-1] - leftc[i] - honey[i];
        }
    }
    answer = max(answer, temp + rightc[0] - honey[0]);

    temp = 0;
    for(int i = N-2 ; i >= 1 ; i--) // 통이 가장 왼쪽, 꿀벌 하나가 가장 오른쪽 고정이고 나머지 꿀벌의 위치
    {
        if(rightc[0] - rightc[i] - honey[i] > temp)     // 나머지 꿀벌 하나가 갖는 최댓갑 확인
        {
            temp = rightc[0] - rightc[i] - honey[i];
        }
    }
    answer = max(answer, temp + rightc[0] - honey[N-1]);

    temp = 0;
    for(int i = 1 ; i < N-1 ; i++)  // 꿀벌 두마리가 양쪽 끝에 고정이고 통의 위치
    {
        if(leftc[i] + rightc[i] > temp)                 // 벌통의 위치에 따른 최댓값 확인
        {
            temp = leftc[i] + rightc[i];
        }
    }
    answer = max(answer, temp - honey[0] - honey[N-1]);

    cout << answer << endl;
}