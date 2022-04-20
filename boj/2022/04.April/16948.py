N = int(input())
r1,c1,r2,c2 = map(int, input().split())
visited = [[False for _ in range(N)] for _ in range(N)]
visited[r1][c1] = True
q = [(r1, c1)]
cnt = 0
while len(q):
    nq = []
    for r, c in q:
        if (r, c) == (r2, c2):
            print(cnt)
            exit()
        for nr, nc in ((r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)):
            if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc]:
                nq.append((nr, nc))
                visited[nr][nc] = True
    q = nq
    cnt += 1
print(-1)