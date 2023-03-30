R, C, K = map(int, input().split())
board = [list(map(int, input().strip())) for _ in range(R)]
visited = [[[0 for _ in range(C)] for _ in range(R)] for _ in range(K+1)]
visited[0][0][0] = 1

dist = 1
q = [(0,0,0)]
while len(q) > 0:
    nq = []
    dist += 1
    for r, c, k in q:
        for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
            if 0 <= nr < R and 0 <= nc < C:
                if board[nr][nc] == 0 and visited[k][nr][nc] == 0:
                    visited[k][nr][nc] = dist
                    nq.append((nr,nc,k))
                elif k+1 <= K and board[nr][nc] == 1 and visited[k+1][nr][nc] == 0:
                    visited[k+1][nr][nc] = dist
                    nq.append((nr,nc,k+1))
    q = nq

ans = [dist[R-1][C-1] for dist in visited if dist[R-1][C-1] > 0]
print(min(ans) if len(ans) > 0 else -1)