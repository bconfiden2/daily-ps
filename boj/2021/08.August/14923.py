from queue import Queue
import sys

N, H = map(int, input().split())
Hx, Hy = map(lambda x:int(x)-1, input().split())
Ex, Ey = map(lambda x:int(x)-1, input().split())
# mat 의 원소값은 0,1,2,3 이 들어갈 수 있음
# 0은 길, 1은 벽, 2는 벽을 부수고 간 사람이 지나간 위치(안부순 사람은 다시 방문 가능), 3은 재방문 불가
mat = [list(map(int, line.split())) for line in sys.stdin]
dire = (1, -1, 0, 0)

q = [(Hx, Hy, False)]
answer = 0
# 시작점부터 BFS 탐색
while len(q) > 0:
    nq = []
    for R, C, broken in q:
        # 목적지 도달 시 거리 출력 후 종료
        if (R, C) == (Ex, Ey):
            print(answer)
            sys.exit()
        for i in range(4):
            nR, nC = R+dire[i], C+dire[3-i]
            if 0 <= nR < N and 0 <= nC < H:
                # 부수고 오지 않았을 경우
                if not broken:
                    # 만약 벽이라면 부시고 감, 벽을 부쉈기 때문에 이 지점 재방문 X
                    if mat[nR][nC] == 1:
                        mat[nR][nC] = 3
                        nq.append((nR, nC, True))
                    # 만약 길이거나 부수고갔던 사람이 방문했을 경우 절대 재방문 될 수 없음
                    elif mat[nR][nC] in (0,2):
                        mat[nR][nC] = 3
                        nq.append((nR, nC, False))
                # 부수고 온 상태에서는 도로일 경우에만 갈 수 있음
                elif mat[nR][nC] == 0:
                    mat[nR][nC] = 2
                    nq.append((nR, nC, True))
    answer += 1
    q = nq

print(-1)