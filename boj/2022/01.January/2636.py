R, C = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(R)]
total = sum(1 for row in board for v in row if v == 1)
cnt = 0
# 전부 녹을때까지 매 시간마다 bfs 로 녹을 친구들 확인
while True:
    visited = [[False for c in range(C)] for r in range(R)]
    q = [(0,0)]
    visited[0][0] = True
    melt = 0
    # 공기에 해당하는 위치들로만 bfs 연결해나가면서, 공기와 인접한 치즈는 녹임
    while len(q) > 0:
        nq = []
        for cr, cc in q:
            for nr, nc in ((cr+1,cc),(cr-1,cc),(cr,cc+1),(cr,cc-1)):
                if 0 <= nr < R and 0 <= nc < C:
                    if not visited[nr][nc]:
                        visited[nr][nc] = True
                        if board[nr][nc] == 1:
                            melt += 1
                            board[nr][nc] = 0
                        else:
                            nq.append((nr, nc))
        q = nq
    # 전부 녹였을 경우 출력 후 종료
    if melt == 0:
        print(f"{cnt}\n{prev}")
        break
    prev = total
    total -= melt
    cnt += 1