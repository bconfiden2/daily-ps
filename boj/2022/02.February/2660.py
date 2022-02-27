import sys
N = int(input())
graph = [[10**10 for c in range(N)] for r in range(N)]
for line in sys.stdin:
    p, q = map(lambda x: int(x)-1, line.split())
    if p == -2:
        break
    graph[p][q] = 1
    graph[q][p] = 1

# 플로이드-와샬로 모든 사람들 사이의 최단 거리 구함
for k in range(N):
    # 항상 자기 자신으로는 연결되게
    graph[k][k] = 1
    for r in range(N):
        for c in range(N):
            graph[r][c] = min(graph[r][c], graph[r][k] + graph[k][c])
mins = [max(row) for row in graph]
ans = min(mins)
cand = [str(i+1) for i,v in enumerate(mins) if v==ans]
print(ans, len(cand))
print(" ".join(cand))