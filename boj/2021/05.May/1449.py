N, L = map(int, input().split())
breaks = sorted(map(int, input().split()))  # 가까운 구멍부터 차례대로 돌기 위해 정렬해놓음
cover = cnt = 0

for cur in breaks:                          # 구멍을 하나씩 확인하면서
    if cover < cur:                         # 이전의 테이프로 막히지 않은 구멍이라면
        cover = cur + L - 0.5               # 테이프를 길이만큼 붙임
        cnt += 1

print(cnt)
