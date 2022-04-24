R, C = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(R)]
dist = [[-1 for _ in range(C)] for _ in range(R)]
q = [(r,c) for r in range(R) for c in range(C) if graph[r][c] == 2]
dist[q[0][0]][q[0][1]] = 0
cnt = 1
# 특정 지점에서 목표지점까지의 거리 == 목표지점에서 해당 지점까지의 거리
# 목표지점부터 시작해 bfs 로 다른 모든 지점들까지의 각 거리를 구하기
while q:
    nq = []
    for r, c in q:
        for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
            if 0 <= nr < R and 0 <= nc < C:
                if graph[nr][nc] != 0 and dist[nr][nc] == -1:
                    dist[nr][nc] = cnt
                    nq.append((nr, nc))
    q = nq
    cnt += 1

# 원래 갈 수 없는 땅은 0 을 출력
# 도달할 수 없는 땅은 -1 을 그대로 출력
for r in range(R):
    for c in range(C):
        if graph[r][c] == 0:
            dist[r][c] = 0
for row in dist:
    print(" ".join(map(str, row)))