N = int(input())
cards = [0] + list(map(int, input().split()))   # 입력받는 각 카드팩의 비용
scores = [0] * 1001                             # i개의 카드를 구매할때의 최댓값
for i in range(1,N+1):                          # scores 리스트를 채워나감. (1개~N개 최댓값들)
    scores[i] = max(scores[idx] + cards[i-idx] for idx in range(i)) # 각 최댓값은, (idx개 카드 최댓값 + 남은 카드갯수뭉치의 비용) 들 중 최댓값이 됨.
print(scores[N])