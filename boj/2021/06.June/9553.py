import math

def probability(x1, y1, x2, y2):
    return (math.acos((x1*x2+y1*y2)/math.sqrt((x1**2+y1**2)*(x2**2+y2**2)))) / (2*math.pi)    # 그 외는 전체 각도 360도 중에서 선분이 차지하는 각도의 비율이 확률

for tc in range(int(input())):      # 각 테스트케이스 별로 N 개 선분들이 갖는 확률들의 합 포매팅해서 출력
    print(f"{round(sum([probability(*list(map(int, input().split()))) for i in range(int(input()))]), 5):.5f}")
