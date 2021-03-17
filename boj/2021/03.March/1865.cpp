#include <iostream>
#include <vector>

#define INF 100000000

using namespace std;

int TC;
int N, M, W;

bool bf()       // 음의 싸이클 존재 여부 리턴
{
    cin >> N >> M >> W;
    vector<pair<pair<int,int>,int>> edges;      // 입력받는 모든 엣지들 저장
    int s, e, t;
    for(int m = 0 ; m < M ; m++)
    {
        cin >> s >> e >> t;
        edges.push_back({{s,e},t});             // 양방향으로 저장
        edges.push_back({{e,s},t});
    }
    for(int w = 0 ; w < W ; w++)
    {
        cin >> s >> e >> t;
        edges.push_back({{s,e},-t});
    }
    vector<int> dist(N+1, 0);                 // 거리 정보, 대충 초기화
    dist[1] = 0;                                // 시작점은 아무데나 설정
    for(int v = 0 ; v < N ; v++)                // n-1 번 반복으로 최단거리 구하고, 마지막 1번으로 변화 유무 파악
    {
        for(int i = 0 ; i < edges.size() ; i++) // 모든 엣지를 보면서
        {
            int start = edges[i].first.first, end = edges[i].first.second;
            if((dist[end] > dist[start] + edges[i].second))         // 거리 갱신되는 노드들 업데이트
            {
                if(v == N-1) return true;                           // 마지막 반복이었을 경우, 거리 갱신 시 음의 싸이클 존재
                dist[end] = dist[start] + edges[i].second;
            }
        }
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
    for(int tc = 0 ; tc < TC ; tc++)
    {
        if(bf()) cout << "YES" << endl;     // 음의 싸이클이 존재할 경우에 따라 답 출력
        else cout << "NO" << endl;
    }
}