import sys
import heapq
N = int(input())
cards = [int(w) for w in sys.stdin]
# 입력받은 카드들 우선순위큐로 만든 다음
heapq.heapify(cards)
answer = 0
# 더 이상 합칠 카드가 없을때까지 가장 작은 카드뭉치 두개를 하나로 합침
while len(cards) > 1:
    tmp = heapq.heappop(cards) + heapq.heappop(cards)
    heapq.heappush(cards, tmp)
    answer += tmp
print(answer)