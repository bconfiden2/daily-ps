import sys
N = int(input())
# 선들을 x 의 오름차순으로 정렬
pos = sorted([tuple(map(int, line.split())) for line in sys.stdin])

answer = 0
# 현재 이어지고 있는 선분 cx, cy
cx, cy = pos[0]
for x, y in pos[1:]:
    # 만약 다음 선분이 현재 선분을 벗어날 경우 현재 길이를 더해주고 선분 교체
    if x > cy:
        answer += cy-cx
        cx, cy = x, y
    # 현재 선분을 벗어나지는 않지만 y 좌표가 더 늘어날 경우
    elif y > cy:
        cy = y
# 맨 마지막 선분도 적용시켜준 뒤 정답 출력
answer += cy-cx
print(answer)