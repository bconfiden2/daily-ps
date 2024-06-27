import sys
sys.setrecursionlimit(200000)
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(lambda x: int(x)-1, input().split())
    graph[u].append(v)
    graph[v].append(u)

CNT = 1
visited = [0 for _ in range(N)]
def dfs(i):
    global CNT
    visited[i] = CNT
    CNT += 1
    for nxt in sorted(graph[i]):
        if visited[nxt] == 0:
            dfs(nxt)
    
dfs(R-1)

for v in visited:
    print(v)
