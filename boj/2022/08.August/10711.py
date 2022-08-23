R, C = map(int, input().split())
origin = [list(map(lambda x: int(x) if x!='.' else 0, input())) for _ in range(R)]
board = [[v for v in row] for row in origin]

# 첫 파도에 무너질 모래성(시작점)들 구해놓음
q = []
for r in range(R):
    for c in range(C):
        if origin[r][c] == 0:
            for dr in range(-1, 2):
                for dc in range(-1, 2):
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < R and 0<= nc < C:
                        if board[nr][nc] > 0:
                            board[nr][nc] -= 1
                            if board[nr][nc] == 0:
                                q.append((nr, nc))

# 시작지점들로부터 BFS를 통해 차례차례 무너질 수 있는 위치 확인
# 어차피 처음에 무너지지 않는 모래성들은, 근처에 있던 다른 모래성이 무너져야만 무너질 가능성이 생기기 때문
cnt = 0
while len(q):
    nq = []
    for r, c in q:
        # 8개 방향으로 확인하면서
        for dr in range(-1, 2):
            for dc in range(-1, 2):
                nr, nc = r+dr, c+dc
                if board[nr][nc] > 0:
                    # 자기 주변에 있는 모래성들을 깎아내서
                    board[nr][nc] -= 1
                    # 무너지는 모래성은 다음 너비에서 다시 탐색
                    if board[nr][nc] == 0:
                        nq.append((nr, nc))
    q = nq
    cnt += 1
print(cnt)
