N = int(input())
cur = 2
while N > 1:
    if N % cur == 0:
        N /= cur
        print(cur)
    else:
        cur += 1