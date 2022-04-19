ins = lambda: map(int, input().split())
N, K = ins()
graph = [list(ins()) for _ in range(N)]
S, X, Y = ins()

# 번호가 낮은 순서대로 BFS 탐색
q = sorted((graph[r][c],r,c) for r in range(N) for c in range(N) if graph[r][c] != 0)
for s in range(S):
    nq = []
    for p, r, c in q:
        for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
            # 낮은 바이러스부터 전파시켜놓음으로써 다른 바이러스는 확산되지 않게
            if 0 <= nr < N and 0 <= nc < N and graph[nr][nc] == 0:
                graph[nr][nc] = p
                nq.append((p, nr, nc))
    q = sorted(nq)
print(graph[X-1][Y-1])