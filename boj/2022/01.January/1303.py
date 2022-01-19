def dfs(r, c, flg):
    cnt = 1
    graph[r][c] = -1
    for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < R and 0 <= nc < C:
            if graph[nr][nc] == flg:
                cnt += dfs(nr, nc, flg)
    return cnt

C, R = map(int, input().split())
graph = [list(map(lambda x: 1 if x=='W' else 0, input())) for r in range(R)]
a, b = 0, 0
for r in range(R):
    for c in range(C):
        if graph[r][c] == 1:
            a += (dfs(r, c, 1) ** 2)
        elif graph[r][c] == 0:
            b += dfs(r, c, 0) ** 2
print(a, b)
