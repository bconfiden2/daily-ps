N = int(input())
# dp[i][j][k] = 길이가 i 이며, 마지막이 j 로 끝났으며, 지금까지 등장한 숫자들을 비트로 표현했을 때의 계단수의 개수
dp = [[[0 for _ in range(1024)] for _ in range(10)] for _ in range(N+1)]
# 길이가 1인 경우 0 시작 제외
for i in range(1, 10):
    dp[1][i][2**i] = 1
for i in range(2, N+1):
    for j in range(10):
        for k in range(1024):
            # 이번에 j 가 등장한다면, 이전에 j-1 혹은 j+1 로 끝난 모든 수들을
            # j 를 방문했을때 변화되는 k 의 비트에다가 더해줌
            x = k | (1 << j)
            # 마지막이 0으로 끝난 경우
            if j > 0: dp[i][j][x] += dp[i-1][j-1][k]
            # 마지막이 9로 끝난 경우
            if j < 9: dp[i][j][x] += dp[i-1][j+1][k]
            dp[i][j][x] %= 1000000000
# 길이가 N일때 0부터 9까지 모든 숫자가 등장한(k=1023) 계단수의 개수
print(sum(dp[N][i][1023] for i in range(10)) % 1000000000)