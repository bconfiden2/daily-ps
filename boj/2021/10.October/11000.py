import sys
input = sys.stdin.readline
import heapq
pq = []
# 강의들을 시작시간 순으로 정렬
for s, t in sorted(tuple(map(int, input().split())) for i in range(int(input()))):
    # 가장 빨리 끝나는 강의시간에 들어갈 수 있으면 해당 강의를 빼고
    if pq and pq[0] <= s:
        heapq.heappop(pq)
    # 이번 강의 추가 (가장 빨리 끝나는 강의실에도 못들어가면 새로운 강의실 추가되는 방식)
    heapq.heappush(pq, t)
# 끝날 때 pq에 남아있는 강의 수가 전체 강의실 수
print(len(pq))