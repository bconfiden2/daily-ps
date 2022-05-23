import sys
from bisect import bisect_left

N = int(input())
A, B = [], []
# 전깃줄 A 기준으로 정렬
for a, b in sorted(tuple(map(int, line.split())) for line in sys.stdin):
    A.append(a)
    B.append(b)

# LIS 를 nlogn 으로 구하기
dp = [B[0]]
# 트래킹
adx = [i for i in range(N)]
for i in range(1, N):
    if B[i] > dp[-1]:
        dp.append(B[i])
    x = bisect_left(dp, B[i])
    dp[x] = B[i]
    adx[i] = x

print(N - len(dp))
lis = set()
order = len(dp)-1
# 역순으로 탐색하여 LIS 에 속하는 원소들 구하기
for i in range(N-1, -1, -1):
    if adx[i] == order:
        lis.add(i)
        order -= 1
    if order == -1:
        break
print('\n'.join(str(A[i]) for i in range(N) if i not in lis))