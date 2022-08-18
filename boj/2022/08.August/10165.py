import sys

N = int(input())
M = int(input())
arr = []
num = 1
for line in sys.stdin:
    a, b = map(int, line.strip().split())
    # 모든 노선을 한쪽 방향으로 통일
    if a > b:
        b += N
    # 도착지점을 먼 순서로 정렬하기 위해 음수로 삽입
    arr.append((a, -b, num))
    num += 1


tmp = []
bea = beb = -1
for a, b, n in sorted(arr):
    b = -b
    # 시작지점이 동일한 경우는 도착지점이 가장 먼 노드만 남겨놓음
    # 이전 노선에서의 가장 먼 도착지점보다 현재 노선의 가장 먼 도착지점이 가까울 경우 해당 노선 모두 제외
    if a == bea or b <= beb:
        continue
    bea, beb = a, b
    tmp.append((a, b, n))

# 마지막 노선이 덮을 수 있는 노선들을 확인
answer = []
for a, b, n in tmp:
    if b + N > beb:
        answer.append(n)
print(' '.join(map(str, sorted(answer))))