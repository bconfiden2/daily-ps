import sys
sys.setrecursionlimit(100000)

input = sys.stdin.readline
N, R, Q = map(int, input().split())
graph = [[] for i in range(N+1)]
answer = [0 for i in range(N+1)]
visited = [False for i in range(N+1)]

# dfs 탐색을 통해 각 노드마다 자기를 루트로 하는 서브트리의 노드 수를 저장
def dfs(cur):
    visited[cur] = True
    # 자기 자신을 포함하기 떄문에 1개로 시작
    tmp = 1
    for cnode in graph[cur]:
        # 방문한 노드(부모 노드)는 제외
        if visited[cnode]:
            continue
        # 자기 자식 트리의 서브노드 수를 더해줌
        tmp += dfs(cnode)
    # answer 에 자기 노드 갱신
    answer[cur] = tmp
    # 부모한테 자기 값을 알려줌
    return tmp

# 그래프는 양방향으로 연결
for _ in range(N-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
dfs(R)
for _ in range(Q):
    print(answer[int(input())])