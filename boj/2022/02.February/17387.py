def pr(p1, p2): return p1[0]*p2[1]-p2[0]*p1[1]
def vec(p1, p2): return (p2[0]-p1[0],p2[1]-p1[1])
def check(X1, X2, X3, X4):
    # 특정 선분을 기준으로 다른 선분의 두 꼭짓점과 외적시킴
    t1 = pr(vec(X1,X2), vec(X1,X3)) * pr(vec(X1,X2), vec(X1,X4))
    t2 = pr(vec(X3,X4), vec(X3,X1)) * pr(vec(X3,X4), vec(X3,X2))
    # 둘 다 0인 경우는 선분이 일직선상에 있다는 뜻이므로, 일직선에 겹치는 부분이 있는지 확인
    if t1 == 0 and t2 == 0:
        return min(X1[0],X2[0]) <= max(X3[0],X4[0]) and\
               min(X3[0],X4[0]) <= max(X1[0],X2[0]) and\
               min(X1[1],X2[1]) <= max(X3[1],X4[1]) and\
               min(X3[1],X4[1]) <= max(X1[1],X2[1])
    # 특정 선분을 기준으로 두 점과의 외적값 부호가 다르면 해당 선분의 양쪽으로 퍼져있다는 뜻
    # 두 선분 모두 부호가 달라야함(같은 경우는 선분에 꼭짓점이 있는 경우)
    return t1 <= 0 and t2 <= 0

x1,y1,x2,y2 = map(int, input().split())
x3,y3,x4,y4 = map(int, input().split())
print(int(check((x1,y1),(x2,y2),(x3,y3),(x4,y4))))