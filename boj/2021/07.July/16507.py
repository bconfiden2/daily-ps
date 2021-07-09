import sys

R, C, Q = map(int, input().split())
img = [[0]*(C+1)] + [[0]+list(map(int, input().split())) for i in range(R)]
dp = [[0 for c in range(C+1)] for r in range(R+1)]

for r in range(1, R+1):
    for c in range(1, C+1):
        dp[r][c] = dp[r-1][c]+dp[r][c-1]-dp[r-1][c-1]+img[r][c]     # dp[r][c] 는 1,1 부터 r,c 까지의 누적합

for line in sys.stdin:
    r1, c1, r2, c2 = map(int, line.split())                         # 모든 구간의 누적합을 알고 있으므로, 입력 받는 좌표들에 대해서 
    print((dp[r2][c2]+dp[r1-1][c1-1]-dp[r1-1][c2]-dp[r2][c1-1]) // ((r2-r1+1)*(c2-c1+1)))   # 해당 구간의 누적합을 구하기 위해, 포함되지 않는 직사각형을 잘라냄