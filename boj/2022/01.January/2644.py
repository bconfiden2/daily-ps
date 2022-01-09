import sys
input = sys.stdin.readline
n = int(input())
start, end = map(lambda x: int(x)-1, input().split())
graph = [[] for _ in range(n)]
for _ in range(int(input())):
    x, y = map(lambda x: int(x)-1, input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = [False for _ in range(n)]
visited[start] = True
q = [start]
ans = 0
while len(q) > 0:
    nq = []
    for cur in q:
        if cur == end:
            print(ans)
            sys.exit()
        for nxt in graph[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                nq.append(nxt)
    q = nq
    ans += 1
print(-1)