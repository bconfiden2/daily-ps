# 루트에 해당하는 비용 부분을, 연결된 모든 자식들의 비용 중 최소값으로 설정
def find(x, c):
    if parent[x] == x:
        cost[x] = min(cost[x], c)
        return x
    parent[x] = find(parent[x], c)
    return parent[x]

import sys
ipt = lambda: map(int, sys.stdin.readline().split())
N, M, k = ipt()
cost = [0] + list(ipt())

parent = [i for i in range(N+1)]
for _ in range(M):
    p, q = ipt()
    # find 과정에서 각 리프들의 비용을 넘겨줌으로써 루트를 찾아가 갱신
    P, Q = find(p, cost[p]), find(q, cost[q])
    if P != Q:
        parent[P] = Q
        # 두 트리를 연결할 때에도 최소값 갱신
        cost[Q] = min(cost[P], cost[Q])

ans = sum(cost[i] for i in range(1, N+1) if parent[i]==i)
print(ans if ans <= k else "Oh no")