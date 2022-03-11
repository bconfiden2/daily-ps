import sys, heapq
V, E = map(int, input().split())
graph = [[10**8 for c in range(V)] for r in range(V)]
for line in sys.stdin:
    a, b, c = map(int, line.split())
    graph[a-1][b-1] = c
# 플로이드와샬로 모든 최단거리 구해놓은 뒤
for k in range(V):
    for r in range(V):
        for c in range(V):
            graph[r][c] = min(graph[r][c], graph[r][k]+graph[k][c])
# 왕복거리가 가장 짧은 구간 확인
ans = min(graph[r][c] + graph[c][r] for r in range(V) for c in range(V))
print(ans if ans < 10**8 else -1)