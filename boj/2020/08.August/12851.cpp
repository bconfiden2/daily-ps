#include <iostream>
#include <queue>

using namespace std;

int n, k;
int answer, ways;           // answer 은 동생을 찾는 시간, ways 는 찾는 방법의 수
int visited[100001];        // 해당 위치에 도달한 시간을 저장(가장 처음 도착한 시간대)
queue<int> q;

void check(int position)
{
    if(0 > position || position > 100000) return;               // 인덱스 검사
    if(visited[position] == 0 || visited[position] == answer)   // 방문하지 않은 위치이거나, 같은 시간대에 방문하는 위치일 경우
    {
        visited[position] = answer;                             // 방문 시간대 처리
        q.push(position);                                       // 큐에 넣어줌
    }
}

int main(void)
{
    cin >> n >> k;

    q.push(n);
    visited[n] = -1;

    while(q.size())
    {
        int size = q.size();
        for(int i = 0 ; i < size ; i++)                 // 같은 시간대에 처리할 위치들을 한번에 처리
        {
            int curPos = q.front();
            q.pop();

            if(curPos == k) ways++;                     // 해당 시간대에 동생에게 도달할 수 있는 모든 값들 카운트

            check(curPos - 1);                          // 3가지 위치를 확인하여 푸시
            check(curPos + 1);                          // 같은 시간대에서 같은 위치에 도달하는 경우엔 중복 허용
            check(curPos * 2);
        }

        if(ways) break;                                 // 만약 동생에게 도달했을 경우 종료
        answer++;                                       // 그 외에는 시간 1 증가
    }
    cout << answer << endl << ways << endl;
}