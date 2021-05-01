#include <iostream>
#include <queue>

using namespace std;

int N, M, temp1, temp2;
pair<int,int> ladders[30];      // 사다리와 뱀 둘 다 포함
bool visited[101];
int answer = 0;

int main(void)
{
    cin >> N >> M;
    for(int i = 0 ; i < N + M ; i++)
    {
        cin >> temp1 >> temp2;
        ladders[i] = {temp1, temp2};
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;          // 1 에서 출발하여 bfs 시작

    while(true)
    {
        int sz = q.size();
        for(int s = 0 ; s < sz ; s++)
        {
            int cur = q.front();
            q.pop();
            
            for(int i = 1 ; i <= 6 ; i++)           // 주사위 1~6 까지 모두 고려
            {
                int next = cur + i;
                if(visited[next]) continue;         // 이전에 방문한 위치면 스킵
                visited[next] = true;
                for(int n = 0 ; n < N + M ; n++)    // 사다리나 뱀에 연결된 위치라면
                {
                    if(next == ladders[n].first)
                    {
                        next = ladders[n].second;   // 타고 올라가거나 내려감
                        break;
                    }
                }
                if(next > 100) continue;

                if(next == 100)                     // 다음 위치가 목적지라면 종료
                {
                    cout << answer+1 << endl;
                    return 0;
                }

                q.push(next);
            }
        }
        answer++;
    }
}