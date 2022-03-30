K = int(input())
C, R = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(R)]
visited = [[[False for _ in range(K+1)] for _ in range(C)] for _ in range(R)]
visited[0][0][0] = True
q = [(0,0,0)]
cnt = 0
while len(q) > 0:
    nq = []
    for r, c, k in q:
        if (r,c) == (R-1,C-1):
            print(cnt)
            exit()
        # 원숭이 모드 + 말 모드로 갈 수 있는 다음 노드 후보들 모두 탐색
        for nr, nc, nk in ((r+1,c,k),(r-1,c,k),(r,c+1,k),(r,c-1,k),\
            (r-1,c+2,k+1),(r-2,c+1,k+1),(r-2,c-1,k+1),(r-1,c-2,k+1),\
            (r+1,c-2,k+1),(r+2,c-1,k+1),(r+2,c+1,k+1),(r+1,c+2,k+1)):
            if 0 <= nr < R and 0 <= nc < C and nk <= K and not visited[nr][nc][nk]:
                if graph[nr][nc] != 1:
                    visited[nr][nc][nk] = True
                    nq.append((nr, nc, nk))
    q = nq
    cnt += 1
print(-1)