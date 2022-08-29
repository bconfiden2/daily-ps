import heapq
N = int(input())
dasom = int(input())
arr = [0] + [-int(input()) for _ in range(N-1)]
heapq.heapify(arr)

cnt = 0
while dasom <= -arr[0]:
    heapq.heappush(arr, heapq.heappop(arr)+1)
    dasom += 1
    cnt += 1
print(cnt)