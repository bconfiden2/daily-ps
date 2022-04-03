import sys
input = lambda: map(int, sys.stdin.readline().split())
N, Q = input()
graph = [[] for _ in range(N+1)]
degree = [0 for _ in range(N+1)]
for _ in range(N):
    a, b = input()
    degree[a] += 1
    degree[b] += 1
    graph[a].append(b)
    graph[b].append(a)

# 차수가 1인 노드들을 순서대로 지워나가면 최종적으로 싸이클 그래프만 남게 됨
visited = [-1 for _ in range(N+1)]
q = [i for i,v in enumerate(degree) if v==1]
while len(q) > 0:
    nq = []
    for cur in q:
        # 자신에게 연결된 다음 노드들 중에
        for nxt in graph[cur]:
            # 아직 방문하지 않은 노드에 대해서
            if visited[nxt] == -1:
                # 자신의 부모로써 취급해주고
                visited[cur] = nxt
                # 자신을 방문처리(부모의 차수 -1)
                degree[nxt] -= 1
                if degree[nxt] == 1:
                    nq.append(nxt)
    q = nq

# 각 서브트리별로 같은 루트를 바라보게끔 만드는 함수
def zp(x):
    # 이미 자신이 루트노드란 걸 아는 경우
    if visited[x] == x: return x
    # 루트노드인줄 몰랐던 경우
    if visited[x] == -1:
        visited[x] = x
        return x
    # 그 외에는 재귀적으로 부모를 쭉쭉 따라가며 자신의 루트를 설정
    visited[x] = zp(visited[x])
    return visited[x]

for i in range(1, N+1):
    zp(i)

ans = []
for _ in range(Q):
    u, v = input()
    # 두 노드가 같은 서브트리에 있으면 경로는 1개, 그 외에는 모두 2개
    ans.append("1" if visited[u]==visited[v] else "2")
print("\n".join(ans))