def bfs(r, c):
    v, o = 0, 0
    q = [(r,c)]
    visited[r][c] = True
    while len(q) > 0:
        nq = []
        for r, c in q:
            if graph[r][c] == 'v': v += 1
            if graph[r][c] == 'o': o += 1
            for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                if 0 <= nr < R and 0 <= nc < C:
                    if not visited[nr][nc] and graph[nr][nc] != '#':
                        visited[nr][nc] = True
                        nq.append((nr, nc))
        q = nq
    return (v, 0) if v >= o else (0, o)

R, C = map(int, input().split())
graph = [list(input()) for _ in range(R)]
visited = [[False for _ in range(C)] for _ in range(R)]
V, O = 0, 0
for r in range(R):
    for c in range(C):
        if not visited[r][c] and graph[r][c] != '#':
            v, o = bfs(r, c)
            V += v
            O += o
print(O, V)