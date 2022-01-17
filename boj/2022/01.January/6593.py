def bfs(bd, a, b, c, L, R, C):
    x = 1
    q = [(a,b,c)]
    bd[a][b][c] = 0
    while len(q) > 0:
        nq = []
        for l,r,c in q:
            for nl, nr, nc in ((l,r+1,c),(l,r-1,c),(l,r,c+1),(l,r,c-1),(l+1,r,c),(l-1,r,c)):
                if 0 <= nl < L and 0 <= nr < R and 0 <= nc < C:
                    if bd[nl][nr][nc] != 0:
                        if bd[nl][nr][nc] == 1:
                            return x
                        nq.append((nl,nr,nc))
                        bd[nl][nr][nc] = 0
        q = nq
        x += 1
    return -1

while True:
    L, R, C = map(int, input().split())
    if L == 0: exit()
    bd = [[[-1 for c in range(C)] for r in range(R)] for l in range(L)]
    a,b,c = 0,0,0
    for l in range(L):
        for r in range(R):
            for d, v in enumerate(input()):
                if v == '#':
                    bd[l][r][d] = 0
                elif v == 'E':
                    bd[l][r][d] = 1
                elif v == 'S':
                    a,b,c = l,r,d
        input()
    x = bfs(bd, a, b, c, L, R, C)
    if x == -1:
        print("Trapped!")
    else:
        print(f"Escaped in {x} minute(s).")