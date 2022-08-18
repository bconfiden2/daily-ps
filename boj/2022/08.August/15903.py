import heapq
N, M = map(int, input().split())
arr = list(map(int, input().split()))
heapq.heapify(arr)

# M번에 걸쳐
for i in range(M):
    # 가장 작은 2개를 뽑아서 더한 값을 2개 넣음
    a, b = heapq.heappop(arr), heapq.heappop(arr)
    heapq.heappush(arr, a + b)
    heapq.heappush(arr, a + b)

print(sum(arr))