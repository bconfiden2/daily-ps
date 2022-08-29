N = int(input())
dic = {input():i for i in range(N)}
order = [dic[input()] for _ in range(N)]
visited = [False for _ in range(N)]

cur = ans = 0
for v in order:
    visited[v] = True
    if v != cur:
        ans += 1
    else:
        while cur < N and visited[cur]:
            cur += 1
print(ans)