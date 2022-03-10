# 5명이 탐색될때까지 재귀적으로 호출
def dfs(i, depth, visited):
    visited[i] = True
    if depth == 4:
        print(1)
        exit()
    for nxt in graph[i]:
        if not visited[nxt]:
            dfs(nxt, depth+1, visited)
    # 백트래킹, 현재 노드가 다른사람에서도 연결될 수 있기 때문
    visited[i] = False

import sys
sys.setrecursionlimit(2000)
N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for line in sys.stdin:
    a, b = map(int, line.split())
    graph[a].append(b)
    graph[b].append(a)
# 가능한 모든 지점에서 검사
for i in range(N):
    dfs(i, 0, [False for _ in range(N)])
print(0)