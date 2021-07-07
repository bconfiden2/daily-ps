#include <iostream>
#include <queue>

#define MAX 4294967295

using namespace std;

struct Node
{
    int position;
    unsigned int time;
    int cnt;
    string path;
};

int limit, num;
unsigned int distances[101];        // 정비소 사이 거리
unsigned int times[101];            // 정비에 걸리는 시간
unsigned int visited[101];          // bfs 에서 불필요한 연산 줄이기 위한 배열
Node answer = {0, MAX, 0, ""};

int main(void)
{
    cin >> limit >> num;
    for(int i = 0 ; i <= num ; i++) cin >> distances[i];
    for(int i = 1 ; i <= num ; i++) cin >> times[i];
    for(int i = 1 ; i <= num ; i++) visited[i] = MAX;
    
    queue<Node> q;
    q.push({0, 0, 0, ""});

    while(q.size())
    {
        Node cur = q.front();
        q.pop();

        int next = cur.position;
        unsigned int cumsum = 0;
        unsigned int next_time = 0;
        while(cumsum + distances[next] <= limit && next <= num)
        {
            cumsum += distances[next++];            // 현재 라이더가 갈 수 있는 모든 정비소를 탐색하기 위한 누적 거리 값
            next_time = cur.time + times[next];     // 현재 소요 시간 + 다음에 들르는 정비소에서 소요되는 시간

            if(next == num + 1)                     // 결승점에 도착하는 경우
            {
                if(next_time < answer.time)         // 따로 큐에 푸시하지 않고 최소 거리일 경우만 비용과 경로 등을 갱신해줌
                {
                    answer.time = next_time;
                    answer.cnt = cur.cnt;
                    answer.path = cur.path;
                }
            }
            else                                    // 결승점에 도달하지 않는 경우(아직 오고 있는 중)
            {
                if(next_time < visited[next])       // 이미 해당 정비소에 왔던 사람보다 빨리 온 경우에만 큐에 새로 푸시
                {
                    visited[next] = next_time;
                    q.push({next, next_time, cur.cnt + 1, cur.path + to_string(next) + " "});
                }
            }
        }
    }

    cout << answer.time << endl;
    cout << answer.cnt << endl;
    if(answer.cnt > 0) cout << answer.path << endl;
}