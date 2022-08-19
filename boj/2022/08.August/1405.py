N, e, w, s, n = map(int, input().split())
prob = tuple(map(lambda x: x/100, (e, w, s, n)))
visited = [[False for _ in range(31)] for _ in range(31)]

def bt(r, c, depth, cur):
    if depth == N:
        return cur
    ret = 0
    for (nr, nc), p in zip(((r,c+1),(r,c-1),(r+1,c),(r-1,c)), prob):
        if 0 <= nr <= 30 and 0 <= nc <= 30 and not visited[nr][nc]:
            visited[nr][nc] = True
            ret += bt(nr, nc, depth+1, cur*p)
            visited[nr][nc] = False
    return ret

visited[15][15] = True
print(bt(15, 15, 0, 1))