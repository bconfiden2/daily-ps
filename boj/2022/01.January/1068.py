N = int(input())
graph = [[] for _ in range(N)]
for i, x in enumerate(map(int, input().split())):
    if x != -1:
        graph[x].append(i)
    else:
        root = i
target = int(input())
# bfs 로 돌면서 리프노드 개수 확인
q = [root]
cnt = 0
while len(q) > 0:
    nq = []
    for cur in q:
        if cur == target:
            continue
        # 현재 노드에 연결된 자식노드가 없거나,
        # 만약 연결된 자식노드가 한개였는데 그게 지울 노드였을 경우, 이 노드는 리프노드가 됨 
        if len(graph[cur]) == 0 or (len(graph[cur])==1 and graph[cur][0] == target):
            cnt += 1
            continue
        for nxt in graph[cur]:
            nq.append(nxt)
    q = nq
print(cnt)