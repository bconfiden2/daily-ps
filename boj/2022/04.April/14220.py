n = int(input())
# dp[i][j] = 노드 j 에서 i 개의 도시를 방문할 때의 최단 거리
dp = [[10**10 for _ in range(n)] for _ in range(n)]
dp[0] = [0 for _ in range(n)]
graph = [[] for _ in range(n)]
for r in range(n):
    for c, v in enumerate(map(int, input().split())):
        if v != 0:
            graph[r].append((c, v))
# 특정 노드가 i개 도시를 방문할때의 최단 거리
# = (연결된 다음 노드들이 각자 i-1개 도시를 방문할때의 최단 거리 + 이번 에지의 거리) 중의 최소값
for i in range(1, n):
    for cur in range(n):
        if len(graph[cur]) > 0:
            dp[i][cur] = min(dp[i-1][nxt] + nv for nxt, nv in graph[cur])
ans = min(dp[n-1])
print(ans if ans != 10**10 else -1)
