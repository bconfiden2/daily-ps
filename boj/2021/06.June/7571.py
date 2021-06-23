import sys

N, M = map(int, input().split())
points = [tuple(map(int, line.split())) for line in sys.stdin]
target = (sorted([p[0] for p in points])[M//2], sorted([p[1] for p in points])[M//2])   # 각 축별 중앙값이 l1 거리의 합이 최소가 되는 점
print(sum([abs(target[0] - p[0]) + abs(target[1] - p[1]) for p in points]))             # 모든 점들과의 거리 계산
