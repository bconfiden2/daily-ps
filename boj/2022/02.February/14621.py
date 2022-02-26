def _find(x):
    if parent[x] == x: return x
    parent[x] = _find(parent[x])
    return parent[x]

import sys, heapq
input = sys.stdin.readline
N, M = map(int, input().split())
gender = [int(v=='M') for v in input().split()]
edges = []
for _ in range(M):
    u, v, d = map(int, input().split())
    heapq.heappush(edges, (d, (u-1, v-1)))

# MST 구하기
ans, cnt = 0, 0
parent = [i for i in range(N)]
while len(edges) > 0:
    d, (u, v) = heapq.heappop(edges)
    # 두 대학교 성이 같으면 연결되지 않음
    if gender[u] == gender[v]:
        continue
    pu, pv = _find(u), _find(v)
    # 순환 이루어지면 연결하면 안됨
    if pu == pv:
        continue
    parent[pv] = pu
    ans += d
    cnt += 1
    # 모든 노드들이 연결된 상태(에지 수가 N-1개)
    if cnt == N-1:
        print(ans)
        exit()
print(-1)