def check(bd, n, r1, r2, c1, c2):
    paper = sum(sum(row[c1:c2]) for row in bd[r1:r2])
    if paper == 0:
        return (1, 0)
    elif paper == n**2:
        return (0, 1)
    else:
        n = n//2
        tmp = [check(bd, n, r1, r1+n, c1, c1+n),
               check(bd, n, r1+n, r2, c1, c1+n),
               check(bd, n, r1, r1+n, c1+n, c2),
               check(bd, n, r1+n, r2, c1+n, c2)]
        return (sum(v[0] for v in tmp), sum(v[1] for v in tmp))

N = int(input())
board = [list(map(int, input().split(' '))) for i in range(N)]
for x in check(board, N, 0, N, 0, N):
    print(x)