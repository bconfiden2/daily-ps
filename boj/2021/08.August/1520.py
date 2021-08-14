M, N = map(int, input().split())
mapp = [list(map(int, input().split())) for r in range(M)]
# visited[r][c] 는 (r, c) 위치에서 (M-1, N-1) 위치까지 가능한 경로의 수
visited = [[-1 for i in range(N)] for j in range(M)]
# 어디에서 들어오든 (M-1, N-1) 은 (M-1, N-1) 까지 1개의 경로라는 뜻
visited[M-1][N-1] = 1
dirr = (1, -1, 0, 0)

# 재귀적으로 가능한 경로들 탐색, DP배열 활용해서 중복탐색 제거
def bt(r, c):
    # (r,c) 위치는 한번도 방문한적이 없을때만 방문하게 되기 때문에 일단 0으로 초기화
    visited[r][c] = 0
    # 해당 위치에서 4방향 탐색하면서
    for i in range(4):
        nr = r + dirr[i]
        nc = c + dirr[3-i]
        if 0 <= nr and nr < M and 0 <= nc and nc < N:
            if mapp[nr][nc] < mapp[r][c]:
                # 탐색하지 않았던 방향이 있으면 탐색해주고
                if visited[nr][nc] == -1:
                    bt(nr, nc)
                # 해당 방향에서 도착지점까지 경로의 수를 현재 위치에 더해줌
                visited[r][c] += visited[nr][nc]

# 첫 위치부터 시작해서 탐색 끝낸 후 visited[0][0] 에는 (M-1,N-1) 까지 가능한 경로가 담겨있음
bt(0, 0)
print(visited[0][0])