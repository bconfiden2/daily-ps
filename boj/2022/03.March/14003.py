from bisect import bisect_left
N = int(input())
A = list(map(int, input().split()))
# adx[i] = A에서 i번째 원소가 dp배열에 위치했던 인덱스값
adx = [i for i in range(N)]
dp = [A[0]]
adx[0] = 0

# nlogn 으로 LIS 구하기 + 인덱스 갱신
for i in range(1, N):
    if A[i] > dp[-1]:
        dp.append(A[i])
    tmp = bisect_left(dp, A[i])
    dp[tmp] = A[i]
    adx[i] = tmp

print(len(dp))
ans = []
# 인덱스를 최대길이부터 역순으로 트래킹 -> 부분수열의 끝부터 탐색하게됨
tmp = len(dp)-1
for i in range(N-1, -1, -1):
    if adx[i] == tmp:
        ans.append(str(A[i]))
        tmp -= 1
print(" ".join(ans[::-1]))