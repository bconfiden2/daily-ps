import sys
sys.setrecursionlimit(10000)
N, M = map(int, input().split())
drc = (1,-1,0,0)
# bing[r][c] 는 (r,c)에 존재하는 빙하의 높이
bing = [list(map(int, line.split())) for line in sys.stdin]
# adj[r][c] 는 (r,c) 주변에 있는 바닷물의 개수
adj = [[sum(1 if bing[r + drc[i]][c + drc[3-i]] == 0 else 0 for i in range(4))\
         if bing[r][c] != 0 else -1 for c in range(M)] for r in range(N)]
# visited[r][c] 는 dfs 탐색 시 해당 위치를 방문했는지에 대한 여부
visited = [[True for c in range(M)] for r in range(N)]

# DFS를 통해 같은 빙산 덩어리들 탐색
def dfs(r, c, visited):
    visited[r][c] = True
    for i in range(4):
        nr = r + drc[i]
        nc = c + drc[3-i]
        if 0 < nr < N-1 and 0 < nc < M-1 and not visited[nr][nc]:
            dfs(nr, nc, visited)

idx = 1
while max(max(row) for row in adj) != -1:
    # 이번 라운드에 전부 녹게 된 빙산을 담을 배열
    checklist = []

    # 빙산들을 전부 검사해서
    for r in range(1,N-1):
        for c in range(1,M-1):
            # 빙산이 있는 위치에 대해서 자기 주변 바닷물만큼 빼줌
            if bing[r][c] > 0:
                bing[r][c] -= adj[r][c]
                # 빙산이 있었는데 이번에 사라지게 됐다면 checklist 에 추가
                if bing[r][c] <= 0:
                    bing[r][c] = 0
                    checklist.append((r,c))
            # dfs 를 위한 visited 배열도 초기화
            visited[r][c] = True if bing[r][c] == 0 else False
    
    # 전부 녹은 빙산에 대해서 주변 빙산들의 adj 값을 바꿔줌
    for r,c in checklist:
        # 현재 빙산은 바닷물로 바꿔주고
        adj[r][c] = -1
        # 4방향에 대해서
        for i in range(4):
            # 주변 위치에 빙산이 있다면 해당 빙산의 adj 값을 1 증가시켜줌
            if adj[r + drc[i]][c + drc[3-i]] != -1:
                adj[r + drc[i]][c + drc[3-i]] += 1

    # 빙산 덩어리 개수 세기
    cnt = 0
    for r in range(N):
        for c in range(M):
            if not visited[r][c]:
                dfs(r, c, visited)
                cnt += 1
    if cnt > 1:
        print(idx)
        break
    idx += 1
else:
    print(0)