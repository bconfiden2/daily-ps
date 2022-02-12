# 섬들을 영역 v 별로 구분짓고, 각 섬의 가장자리에 대한 정보도 저장
def dfs(r, c, v):
    graph[r][c] = v
    for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
        if 0 <= nr < N and 0 <= nc < N:
            if graph[nr][nc] == 0:
                edge[r][c] = True
            if graph[nr][nc] == 1:
                dfs(nr, nc, v)

# 특정 위치(섬의 가장자리)에서 시작하여 다른 섬과의 가장 가까운 거리 반환
def bfs(R, C):
    cnt = 0
    q = [(R,C)]
    v = graph[R][C]
    visited = [[False for c in range(N)] for r in range(N)]
    visited[R][C] = True
    while len(q) > 0:
        nq = []
        for r, c in q:
            for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                if 0 <= nr < N and 0 <= nc < N and not visited[nr][nc]:
                    # 바다일 경우 계속 전진
                    if graph[nr][nc] == 0:
                        nq.append((nr, nc))
                        visited[nr][nc] = True
                    # 다른 섬에 도달한 경우 반환
                    elif graph[nr][nc] != v:
                        return cnt
        q = nq
        cnt += 1
    return 10000

import sys
sys.setrecursionlimit(10000)
N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
edge = [[False for _ in range(N)] for r in range(N)]
area = 2
# 섬들을 영역별로 구분지음
for r in range(N):
    for c in range(N):
        if graph[r][c] == 1:
            dfs(r, c, area)
            area += 1
# 각 섬의 가장자리마다 bfs 를 돌려 가장 가까운 다른 섬과의 거리 출력
print(min(bfs(r,c) for r in range(N) for c in range(N) if edge[r][c]))
