import heapq
for _ in range(int(input())):
    K = int(input())
    arr = list(map(int, input().split()))
    heapq.heapify(arr)
    ans = 0
    for i in range(K-1):
        tmp = heapq.heappop(arr) + heapq.heappop(arr)
        heapq.heappush(arr, tmp)
        ans += tmp
    print(ans)