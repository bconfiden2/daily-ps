N = int(input())
arr = list(map(int, input().split()))
dp = [1 for _ in range(N)]
adx = [1 for _ in range(N)]

# 일반적인 O(N^2) 으로 LIS 구해놓기
for i in range(N):
    for j in range(i):
        if dp[j] >= dp[i] and arr[i] > arr[j]:
            dp[i] = dp[j] + 1
            adx[i] = max(adx[i], dp[i])

# DP 배열을 뒤에서부터 역순으로 탐색하여 최대길이부터 내려감
idx = N-1
tmp = []
ans = max(dp)
print(ans)
for v in range(ans, 0, -1):
    while dp[idx] != v:
        idx -= 1
    tmp.append(str(arr[idx]))
print(" ".join(tmp[::-1]))