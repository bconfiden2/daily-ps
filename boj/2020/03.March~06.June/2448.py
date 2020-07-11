n = int(input())

# 하나의 삼각형을 3*6 짜리 직사각형으로 생각한다.
# 전체 캔버스는 맨 밑줄에 맞춰서 그려준다
canvas = [[' '] * (n//3 * 6) for i in range(n)]

# 삼각형 하나를 그려주기 위한 재귀호출
def fill(k, x, y) :
    # 가장 작은 삼각형을 최종적으로 그려주고 끝내는 부분
    if k == 3 :
        draw(x,y)
        return

    tk = k // 2 # 현재 삼각형의 크기
    fill(tk, x + tk, y) # 위쪽 중간 삼각형 하나
    fill(tk, x, y + tk) # 왼쪽 아래 삼각형 하나
    fill(tk, x + (6 * tk // 3),y + tk) # 오른쪽 아래 삼각형 하나

# 호출된 지점에서 3*6 짜리 직사각형 안에 삼각형 하나를 그려준다
# 호출된 지점은 재귀호출되며 좌표변환이 일어나 캔버스의 절대좌표값이 들어간다
def draw(x,y) :
    canvas[y][x+2] = '*'
    canvas[y+1][x+1] = '*'
    canvas[y+1][x+3] = '*'
    canvas[y+2][x] = '*'
    canvas[y+2][x+1] = '*'
    canvas[y+2][x+2] = '*'
    canvas[y+2][x+3] = '*'
    canvas[y+2][x+4] = '*'

fill(n, 0, 0)

for lines in canvas :
    print(''.join(lines))
