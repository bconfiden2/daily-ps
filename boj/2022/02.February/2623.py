N, M = map(int, input().split())
graph = [[] for _ in range(N)]
degree = [0 for _ in range(N)]
for m in range(M):
    arr = list(map(lambda x: int(x)-1, input().split()))
    for i in range(1, arr[0]+1):
        graph[arr[i]].append(arr[i+1])
        degree[arr[i+1]] += 1

# 위상정렬로 가능한 노드들을 순서대로 탐색
ans = []
q = [i for i,v in enumerate(degree) if v==0]
while len(q) > 0:
    nq = []
    for cur in q:
        ans.append(cur+1)
        for nxt in graph[cur]:
            degree[nxt] -= 1
            if degree[nxt] == 0:
                nq.append(nxt)
    q = nq

# 모든 노드를 순서대로 탐색한 경우(순서가 맞다는 뜻)
if len(ans) == N:
    for v in ans:
        print(v)
else:
    print(0)