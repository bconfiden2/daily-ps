N = int(input())
# arr = 전깃줄을 A 라인 순서대로 정렬한 뒤 매칭되는 B 라인의 값들
arr = [v for _, v in sorted(tuple(map(int, input().split())) for _ in range(N))]
# B 라인에서 가장 긴 부분수열을 만드는 것이, 전깃줄이 교차하지 않는 최대 상태가 됨
dp = [1 for _ in range(N)]
for i in range(1, N):
    for j in range(i):
        if arr[i] > arr[j] and dp[j] >= dp[i]:
            dp[i] = dp[j] + 1
print(N-max(dp))