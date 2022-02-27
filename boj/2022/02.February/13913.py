N, K = map(int, input().split())
visited = [False for _ in range(100001)]
parent = [i for i in range(100001)]

# BFS로 탐색하면서, 특정 노드를 방문하게 만든 부모 노드가 누군지 저장
q = [N]
visited[N] = True
while len(q) > 0:
    nq = []
    for cur in q:
        for nxt in (cur+1,cur-1,cur*2):
            if 0 <= nxt < 100001 and not visited[nxt]:
                visited[nxt] = True
                nq.append(nxt)
                parent[nxt] = cur
    q = nq

# 목적지서부터 출발지에 도착할때까지 부모를 하나씩 따라가면 경로 완성
cur, ans = K, []
while cur != N:
    ans.append(cur)
    cur = parent[cur]
ans.append(N)
print(len(ans)-1)
print(" ".join(map(str, ans[::-1])))