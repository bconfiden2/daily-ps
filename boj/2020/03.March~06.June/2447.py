n = int(input())
canvas = [[' '] * n for i in range(n)]

def draw(k,x,y) :
    if k == 1 :
        canvas[x][y] = '*'
        return
    tk = k//3
    for i in range(3) :
        for j in range(3) :
            if (i != j or i != 1) :
                draw(tk, x + i * tk,  y + j * tk)

draw(n,0,0)

for line in canvas :
    for i in line :
        print(i,end='')
    print()
