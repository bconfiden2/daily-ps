# 유클리드 호제법
def gcd(x, y):
    while y > 0:
        x, y = y, x%y
    return x

# 서로소인 가로세로 박스 안에서, 해당 직선이 지나가는 박스의 개수 반환
def box(x, y):
    return min(x, y) * (max(x,y)//min(x,y)+1) + (max(x,y)%min(x,y)-1) if x!=1 and y!=1 else max(x,y)

def solution(w,h):
    # 가로세로의 최대공약수를 구한 뒤
    G = gcd(w, h)
    # 전체 직사각형 - (최대공약수만큼 나뉜 박스 안에서 사용할 수 없는 칸들) * 박스의 개수
    return w * h - box(w//G, h//G) * G