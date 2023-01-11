N = int(input())
P = list(map(int, input().split()))
M = int(input())

# 방 번호를 가장 크게 만드는 조합 = 아이템의 개수가 가장 많거나, 개수가 동일할 경우 리스트가 내림차순으로 큰 경우

# dp[m][n] = 현재 아이템의 가격만큼 뺀 dp[m-P[n]]에 있는 N개 경우 중
# 이번 아이템을 산다고 했을때 가장 정답에 근접한 경우를 선택
dp = [[[0,[]] for _ in range(N)] for _ in range(M+1)]
for m in range(1, M+1):
    for i in range(N):
        if P[i] > m:
            continue
        pick = max(dp[m-P[i]])
        dp[m][i][0] = pick[0] + 1
        dp[m][i][1] = sorted(pick[1] + [i], reverse=True)

# M원에 해당하는 dp[M] 중에 정답이 되는 값을 찾음
bcnt = 0
blst = [0]
for cnt, lst in dp[M]:
    if sum(lst) > 0:
        if cnt > bcnt:
            bcnt = cnt
            blst = lst
        elif cnt == bcnt and lst > blst:
            blst = lst
print("".join(map(str, blst)))
