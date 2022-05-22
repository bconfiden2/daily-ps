N = '0'+input()
# dp[i] = N의 i번째 자리수를 한자리/두자리로 복호화할때 가능한 경우의 수
dp = [[1,0]] + [[0,0] for _ in range(len(N)-1)]
for i in range(1, len(N)):
    # 한자리로 볼 때
    # 만약 직전 자리수까지 가능한 경우가 없거나, 이번 자리수가 0 일 경우 불가능
    if sum(dp[i-1]) != 0 and int(48 < ord(N[i])):
        dp[i][0] = sum(dp[i-1])
    # 두자리로 볼 때
    # 만약 직전 자리수가 0이거나, 이전을 포함한 두자리수 값이 26보다 클 경우 불가능
    if i > 1 and N[i-1] != '0' and int(N[i-1:i+1]) <= 26:
        dp[i][1] = sum(dp[i-2])
    # 이번 자리수를 가지고 한자리로도, 두자리로도 가능한 경우의 수가 없을 때
    if not sum(dp[i]):
        print(0)
        exit()
print(sum(dp[-1]) % 1000000)