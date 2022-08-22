R, C = map(int, input().split())
graph = [list(input()) for _ in range(R)]
dirs = {'-':((0,1),(0,-1)), '|':((1,0),(-1,0))}

def dfs(r, c, flg):
    graph[r][c] = ' '
    for dr, dc in dirs[flg]:
        nr, nc = r+dr, c+dc
        if 0 <= nr < R and 0 <= nc < C and graph[nr][nc] == flg:
            dfs(nr, nc, flg)
    return 1

print(sum(dfs(r, c, graph[r][c]) for r in range(R) for c in range(C) if graph[r][c] != ' '))
