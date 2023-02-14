R, C, r, c, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(R)]
dice = [0 for _ in range(6)]
dirs = [(0,1),(0,-1),(-1,0),(1,0)]
newdice = [
    [2,1,5,0,4,3],
    [3,1,0,5,4,2],
    [1,5,2,3,0,4],
    [4,0,2,3,5,1]
]

for d in map(lambda x:int(x)-1, input().split()):
    nr, nc = r + dirs[d][0], c + dirs[d][1]
    if 0 <= nr < R and 0 <= nc < C:
        r, c = nr, nc
        dice = [dice[i] for i in newdice[d]]
        if board[r][c] == 0:
            board[r][c] = dice[0]
        else:
            dice[0] = board[r][c]
            board[r][c] = 0
        print(dice[-1])