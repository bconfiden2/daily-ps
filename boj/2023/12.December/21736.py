N, M = map(int, input().split())
bd = [list(input()) for _ in range(N)]
q = []
for r in range(N):
    for c in range(M):
        if bd[r][c] == 'I':
            bd[r][c] = 'X'
            q.append((r,c))
            break
    if len(q) == 1:
        break

answer = 0
while q:
    pq = []
    for r, c in q:
        for nr, nc in ((r,c+1),(r,c-1),(r+1,c),(r-1,c)):
            if 0 <= nr < N and 0 <= nc < M and bd[nr][nc] != 'X':
                pq.append((nr, nc))
                if bd[nr][nc] == 'P':
                    answer += 1
                bd[nr][nc] = 'X'

    q = pq
print('TT' if answer == 0 else answer)