N, K = map(int, input().split())
d = {}
cumsum = answer = 0
for v in map(int, input().split()):
    cumsum += v
    # 전체 누적합이 K 일 경우 1 더해주고
    if cumsum == K: answer += 1
    # 이전까지의 누적합 값들 중 두 값의 차이가 K 인 값이 있으면 그만큼 증가
    answer += d.get(cumsum-K, 0)
    d[cumsum] = d.get(cumsum, 0) + 1
print(answer)