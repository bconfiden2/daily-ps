import sys, heapq
input = sys.stdin.readline
N, K = map(int, input().split())
V, S = [], []
for n in range(N):
    heapq.heappush(V, tuple(map(int, input().split())))

# 가방 크기가 작은 것부터 채워나감
ans = 0
for c in sorted(int(v) for v in sys.stdin):
    while len(V) > 0 and V[0][0] <= c:
        heapq.heappush(S, -heapq.heappop(V)[1])
    # 현재 가방 크기로 담을 수 있는 보석들 중 가장 값이 높은 친구를 저장
    if len(S) > 0: ans += -heapq.heappop(S)
print(ans)