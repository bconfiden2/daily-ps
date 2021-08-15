import heapq

N = int(input())
tops = list(map(int, input().split()))
answer = [0 for i in range(N)]
pq = []

# 뒤에서부터 탐색하면서
for i in range(N-1, -1, -1):
    # 지금까지의 탑들 중 현재 탑이 수신할 수 있는 모든 신호를 수신처리
    while len(pq) > 0 and pq[0][0] <= tops[i]:
        val, idx = heapq.heappop(pq)
        answer[idx] = i+1
    # 현재 탑도 pq 에 추가해주고 계속 앞쪽으로 탐색 진행
    heapq.heappush(pq, (tops[i], i))

for v in answer:
    print(v, end=" ")
print()