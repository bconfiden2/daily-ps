import math
n = int(input())
arr = [0, 1, 2, 3] + [0] * (n - 3)
for i in range(1, math.ceil(math.sqrt(n))):     # 제곱수들은 1로 처리
    arr[i ** 2] = 1
for i in range(4, n+1):                                         # 나머지 수에 대해서
    val = math.floor(math.sqrt(i))                              # 자신보다 작은 수들 중 모든 제곱값들에 대하여
    arr[i] = 1 + min(arr[i - x**2] for x in range(1, val+1))    # (제곱값을 뺀 값의 최소개수) + 1 이 최솟값이 됨
print(arr[n])