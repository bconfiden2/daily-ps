for _ in range(int(input())):
    N = int(input())
    perm = map(lambda x: int(x)-1, input().split())
    graph = [0 for _ in range(N)]
    for i, v in enumerate(perm):
        graph[i] = v
    ans = 0
    visited = [False for _ in range(N)]
    for i in range(N):
        if visited[i]:
            continue
        visited[i] = True
        nxt = graph[i]
        while nxt != i:
            visited[nxt] = True
            nxt = graph[nxt]
        ans += 1
    print(ans)
