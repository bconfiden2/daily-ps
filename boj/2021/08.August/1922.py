import sys
import heapq

N = int(input())
M = int(input())
parents = [-1 for i in range(N+1)]
pq = []
answer = 0

# 자기가 속한 집합의 루트를 찾아감, 경로압축
def find(x):
    if parents[x] == -1: return x
    parents[x] = find(parents[x])
    return parents[x]

# 우선순위큐에 간선이 낮은 순서대로 저장
for line in sys.stdin:
    a, b, c = map(int, line.strip().split())
    heapq.heappush(pq, (c, (a,b)))

while len(pq):
    # 가장 비용이 낮은 노드쌍 순서대로 그래프를 연결시켜나감
    c, (a,b) = heapq.heappop(pq)
    # 각 노드가 속한 집합의 루트노드를 찾아서
    A, B = find(a), find(b)
    # 두 노드가 속한 집합이 같으면 해당 간선 고려하지 않음
    if A != B:
        answer += c
        parents[A] = B

print(answer)