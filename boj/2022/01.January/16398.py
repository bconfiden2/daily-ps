import sys
import heapq
input = sys.stdin.readline
sys.setrecursionlimit(10000)
# 간선은 한쪽 방향만 고려
N = int(input())
pq = []
for r in range(N):
    for c, v in enumerate(input().split()):
        if r < c:
            heapq.heappush(pq, (int(v), (r, c)))
# 순환 확인용 유니온파인드
parents = [i for i in range(N)]
def _find(x):
    if parents[x] == x: return x
    parents[x] = _find(parents[x])
    return parents[x]
# 크루스칼
answer = 0
while len(pq) > 0:
    v, (r, c) = heapq.heappop(pq)
    r, c = _find(r), _find(c)
    if r != c:
        answer += v
        parents[r] = c
print(answer)