N = int(input())
M = int(input())
                                                            # DP[X][Y] 는 X 개의 과일 종류 중 총 Y 개를 뽑는 경우의 수
DP = [[1]*(M-N+1), [1]*(M-N+1)]                             # DP[1][Y] 는 반드시 1.
for X in range(2, N):                                       # DP[X][Y] = sum(a=0~Y, DP[X-1][a])
    DP.append([sum(DP[X-1][:Y+1]) for Y in range(M-N+1)])
print(sum(DP[N-1][:M-N+1]) if N > 1 else 1)                 # DP[N][M-N] 구하기 ,N 이 1 일 경우는 예외처리