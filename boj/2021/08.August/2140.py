N = int(input())
board = [list(input()) for _ in range(N)]

# 왼쪽 위부터 오른쪽 아래까지 순서대로 채워나감
for r in range(N):
    for c in range(N):
        # 가장자리 부분(열린 부분)만 검사
        if board[r][c] in ('#', 'O', 'X'):
            continue
        # target = 내 주변에 채워야 할 폭탄의 수, bombs = 실제로 주변에 폭탄이 얼마나 차있는지
        target = int(board[r][c])
        bombs = 0
        # 해당 위치에서 8개 방향을 확인
        for ir in (-1,0,1):
            for ic in (-1,0,1):
                if ir==0 and ic==0: continue
                nr, nc = r+ir, c+ic
                # 검사할 인접 위치 (nr,nc)의 인덱스 확인한 뒤
                if 0 <= nr < N and 0 <= nc < N:
                    # 아직 채워지지 않은 곳이라면
                    if board[nr][nc] == '#':
                        # 이미 내 할당량의 폭탄이 주변에 다 차있다면 이번 위치는 불가능 표시
                        if bombs == target:
                            board[nr][nc] = 'X'
                        # 아직 채워야 할 폭탄 수가 남아있다면 채워줌
                        else:
                            board[nr][nc] = 'O'
                            bombs += 1
                    # 이전 검사에서 채워진 폭탄들도 셈
                    elif board[nr][nc] == 'O':
                        bombs += 1

# 폭탄을 실제로 채운 위치들 + 검사되지 않은 중간부분은 모두 폭탄으로 처리해서 최대값 구함
print(sum(int(board[r][c] in ('#', 'O')) for r in range(N) for c in range(N)))