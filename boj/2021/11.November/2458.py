import sys
N, M = map(int, input().split())
forward = [[] for _ in range(N+1)]
backward = [[] for _ in range(N+1)]

def dfs(cur, visited, graph):
    visited[cur] = True
    for nxt in graph[cur]:
        if not visited[nxt]:
            dfs(nxt, visited, graph)

# 양방향으로 각각 그래프 생성
for line in sys.stdin:
    a, b = map(int, line.split())
    forward[a].append(b)
    backward[b].append(a)

answer = 0
for i in range(1, N+1):
    visited = [False for x in range(N+1)]
    # 정방향으로 한번 훑어주고
    for x in forward[i]:
        dfs(x, visited, forward)
    # 역방향으로도 한번 훑었는데도
    for x in backward[i]:
        dfs(x, visited, backward)
    # 방문하지 못한 노드가 있으면 비교 불가하다는 뜻
    answer += int(sum(1 for v in visited if v) == N-1)
print(answer)