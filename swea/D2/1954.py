t = int(input())
dr = [0, 1, 0, -1]              # 4방향, 순서는 값의 증가방향인 오른쪽-아래-왼쪽-위쪽
dc = [1, 0, -1, 0]

def change(r, c, value, dir) :
    if value == n**2 :              # 전부 다 채웠으면 재귀 종료
        info[r][c] = value
        return
    if r + dr[dir] not in range(n) or c + dc[dir] not in range(n) :     # 다음 위치 인덱스가 범위를 벗어나거나
        dir += 1    
    elif info[r + dr[dir]][c + dc[dir]] != 0 :                          # 다음 위치가 이미 채워져있는 값이라면
        dir += 1                                                        # 방향을 다음 방향으로 틀고
    dir %= 4                                                            # 만약 위쪽이라면 다시 오른쪽으로 틀어줌
    info[r][c] = value                                                  # 현재 위치에 값을 채우고
    r += dr[dir]
    c += dc[dir]                                                        # 다음 위치로 이동
    change(r, c, value + 1, dir)                                        # 다음 위치의 값 채우는 재귀호출

for tc in range(t) :
    n = int(input())
    print("#" + str(tc+1))
    info = [[0 for i in range(n)] for j in range(n)]        # 2차원 리스트, 0으로 초기화
    change(0, 0, 1, 0)                                      # 재귀호출 시작
    for r in range(n) :                                     # 정답 출력
        for c in range(n) :
            print(info[r][c], end = " ")
        print()