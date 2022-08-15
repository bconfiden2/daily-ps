input()
cnt = maxi = ans = 0
for v in map(int, input().split()):
    if v > maxi:
        ans = max(ans, cnt)
        cnt = 0
        maxi = v
    else:
        cnt += 1
print(max(ans, cnt))