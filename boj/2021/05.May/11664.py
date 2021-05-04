def distance(a, b):
    return (sum((e1-e2)**2 for e1, e2 in zip(a,b))) ** 0.5

Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz = map(int, input().split())

Cx -= Ax
Cy -= Ay
Cz -= Az
Bx -= Ax
By -= Ay
Bz -= Az

A, B, C = (0,0,0), (Bx, By, Bz), (Cx, Cy, Cz)

b = distance(A, B)
x = (Bx * Cx + By * Cy + Bz * Cz) / (Bx * Bx + By * By + Bz * Bz)

P = (x * Bx, x * By, x * Bz)

if x < 0 or x > b:
    print("{:.10f}".format(min(distance(A, C), distance(B, C))))
else:
    print("{:.10f}".format(distance(P, C)))

input()