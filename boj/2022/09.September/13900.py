N = int(input())
arr = list(map(int, input().split()))
tot = sum(arr)

ans = 0
for v in arr:
    tot -= v
    ans += v * tot
print(ans)