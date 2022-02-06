input()
import sys, heapq
sm, bg = [], []
for v in sys.stdin:
    # 일단 최대힙에 넣은 뒤
    heapq.heappush(sm, -int(v))
    # 두 힙의 차이가 1 이하가 될때까지 밸런싱
    while len(sm)-len(bg) > 1:
        heapq.heappush(bg, -heapq.heappop(sm))
    # 중간값이 망가진 경우에는 복구
    if len(bg) > 0 and -sm[0] > bg[0]:
        tmp = heapq.heappop(bg)
        heapq.heappush(bg, -heapq.heappop(sm))
        heapq.heappush(sm, -tmp)
    # 항상 최대힙의 탑에 중간값 유지
    print(-sm[0])