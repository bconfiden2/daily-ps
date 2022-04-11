def get(r, c):
    idx = max(abs(r), abs(c))
    bef = (2*(idx-1) + 1) ** 2
    base = (2*idx + 1) ** 2
    dr, dc = idx-r, idx-c
    return base-dr-dc if r >= c else bef+dr+dc

r1, c1, r2, c2 = map(int, input().split())
ans = [[0 for _ in range(c2-c1+1)] for _ in range(r2-r1+1)]
for r in range(r1, r2+1):
    for c in range(c1, c2+1):
        ans[r-r1][c-c1] = get(r, c)
lg = max(len(str(v)) for row in ans for v in row)
for row in ans:
    print(" ".join(map(lambda x: str(x).rjust(lg), row)))