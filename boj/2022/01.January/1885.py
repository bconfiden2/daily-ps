import sys
n, k = map(int, input().split())
cur, cntr = 1, set()
# 1~k개가 모두 모일때마다 가능한 부분수열의 길이가 1씩 증가
for v in map(int, sys.stdin):
    cntr.add(v)
    if len(cntr) == k:
        cntr.clear()
        cur += 1
print(cur)
