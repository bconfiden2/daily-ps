R, C, N = map(int, input().split())
board = [list(input().strip()) for _ in range(R)]

def cycle():
    pos = []
    for r in range(R):
        for c in range(C):
            if board[r][c] == 'O':
                pos.append((r, c))
                for nr, nc in ((r+1,c),(r-1,c),(r,c+1),(r,c-1)):
                    if 0 <= nr < R and 0 <= nc < C:
                        pos.append((nr, nc))
            board[r][c] = 'O'
    for r, c in pos:
        board[r][c] = '.'

if N == 1:
    print('\n'.join(''.join(row) for row in board))
elif N % 2 == 0:
    print('\n'.join('O'*C for _ in range(R)))
else:
    cycle()
    if (N//2) % 2 == 0:
        cycle()
    print('\n'.join(''.join(row) for row in board))