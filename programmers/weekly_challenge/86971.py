# 특정 노드에서 출발해서 연결된 노드들의 수 반환
def dfs(v, graph, visited):
    visited[v] = True
    return sum([1] + [dfs(u, graph, visited) for u in graph[v] if not visited[u]])
    
def solution(n, wires):
    graph = [[] for _ in range(n+1)]
    for v, u in wires:
        graph[v].append(u)
        graph[u].append(v)
    
    # 간선을 하나씩 잘라냈을 때의 두 차이값들 중 최소값 완전탐색
    answer = 100
    for i in range(n-1):
        visited = [False for _ in range(n+1)]
        v1, v2 = wires[i]
        # v2 방문처리함으로써 v1 과 v2 분리 처리
        visited[v2] = True
        # v1 과 v2 에 각각 dfs 를 통해 나뉜 송전탑의 개수를 확인
        tmp = abs(dfs(v1, graph, visited) - dfs(v2, graph, visited))
        answer = min(tmp, answer)
    return answer