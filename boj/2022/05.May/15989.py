# dp[i][x] = 정수 i를 만드는 값을 크기순으로 정렬했을 때 x가 끝에 올 경우의 수
dp = [[1,0,0] for _ in range(10001)]
dp[2] = [1,1,0]
dp[3] = [1,1,1]
for i in range(4, 10001):
    # 맨 끝이 2가 붙는 경우
    dp[i][1] = sum(dp[i-2][:2])
    # 맨 끝에 3이 붙는 경우
    dp[i][2] = sum(dp[i-3])

for _ in range(int(input())):
    print(sum(dp[int(input())]))
