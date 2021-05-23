#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int TC, N, answer;
int map[125][125];
int dir[4] = {1, -1, 0, 0};

int main(void)
{
    cin >> N;
    while(N)
    {
        for(int r = 0 ; r < N ; r++)
            for(int c = 0 ; c < N ; c++)
                cin >> map[r][c];
        
        vector<int> distance(N*N, INF);             // 다익스트라용 최단거리값 저장, 2차원을 1차원으로 늘려놨음
        distance[0] = map[0][0];                    // 출발지점 값을 거리에 포함시킴
        priority_queue<pair<int,int>> pq;
        pq.push({-distance[0], 0});                 // 최소힙 바꾸는 대신 거리를 음수화

        while(pq.size())
        {
            int dist = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(distance[cur] < dist) continue;
            for(int i = 0 ; i < 4 ; i++)            // 각 노드는 상하좌우 4방향이랑 연결되어있음
            {
                int nextR = cur/N + dir[i];         // 1차원 위치를 2차원으로 바꿔준뒤
                int nextC = cur%N + dir[3-i];       // 가장자리 노드들에 대한 검사
                if(nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;
                int next = N * nextR + nextC;
                int nextDist = map[nextR][nextC] + dist;
                if(nextDist < distance[next])       // 최단 거리가 갱신되는 루트라면
                {
                    distance[next] = nextDist;      // 갱신 후 pq 에 넣어줌
                    pq.push({-nextDist, next});
                }
            }
        }

        cout << "Problem " << ++TC << ": " << distance[N*N-1] << endl;
        cin >> N;
    }
}