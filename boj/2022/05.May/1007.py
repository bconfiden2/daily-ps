from itertools import combinations
for _ in range(int(input())):
    N = int(input())
    points = [tuple(map(int, input().split())) for _ in range(N)]
    TX, TY = sum(p[0] for p in points), sum(p[1] for p in points)
    ans = 10**10
    tmp = list(combinations(points, N//2))
    # 벡터들의 합은 교환법칙이 성립하기 때문에, 단순히 벡터를 뽑고 그 합만 추적하면 됨
    for comb in tmp[:len(tmp)//2]:
        # 이번에 뽑은 벡터들(시작 좌표 기준)의 합을 구한 뒤
        X, Y = sum(p[0] for p in comb), sum(p[1] for p in comb)
        # 해당 벡터들과 뽑히지 않은 벡터들(도착 좌표 기준)의 전체합을 이용하여 모든 벡터의 합 구하기
        ans = min(ans, ((TX-2*X)**2 + (TY-2*Y)**2)**0.5)
    print(ans)