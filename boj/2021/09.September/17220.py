N, M = map(int, input().split())
# 전체 그래프
graph = [[] for _ in range(N)]
# 마약 공급처(dfs 루트노드들)
find_root = [True for _ in range(N)]
# 간선을 입력받아 그래프 구성하고, 루트 노드 후보들 찾아냄
for m in range(M):
    v, u = map(lambda x: ord(x)-65, input().split())
    graph[v].append(u)
    find_root[u] = False
# 경찰에게 검거된 노드들
gg = list(map(lambda x: ord(x)-65, input().split()[1:]))
visited = [False for _ in range(N)]
answer = 0

# dfs 탐색하면서 방문하는 모든 노드는 마약 공급 가능하므로 answer + 1
def dfs(cur):
    global answer
    visited[cur] = True
    for nxt in graph[cur]:
        if not visited[nxt] and nxt not in gg:
            answer += 1
            dfs(nxt)

tmp = [i for i in range(N) if find_root[i]]
# 검거당하지 않은 모든 마약 공급처로부터 출발
for rt in tmp:
    if rt not in gg:
        dfs(rt)
print(answer)