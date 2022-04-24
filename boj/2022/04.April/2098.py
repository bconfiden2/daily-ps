def tsp(x, stat):
    # 만약 모든 노드를 방문한 상태라면, 현재 노드와 시작 노드와 연결되는지 확인하여 반환
    if stat == (1<<N) - 1:
        return 10**10 if graph[x][0] == 0 else graph[x][0]
    # 만약 이전에 방문한 상황이라면 해당 dp값 반환
    if dp[x][stat] != 10**10:
        return dp[x][stat]
    # 모든 노드들에 대해서
    for i in range(N):
        # 다음 노드로 갈 수 있으면서, 이미 방문한 상태가 아닌 경우에
        if graph[x][i] != 0 and stat & (1<<i) == 0:
            # 해당 경로로 움직였을때와 기존 값 중 최단거리로 갱신
            dp[x][stat] = min(dp[x][stat], graph[x][i] + tsp(i, stat|(1<<i)))
    return dp[x][stat]

import sys
sys.setrecursionlimit(100000)
N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
dp = [[10**10 for _ in range(1 << N)] for _ in range(N)]
print(tsp(0, 1))