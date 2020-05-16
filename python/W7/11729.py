def hanoi(n, A, B, C) :
    if n == 1 :
        print("%d %d"%(A, C))
        return
    hanoi(n-1, A, C, B)
    hanoi(1, A, B, C)
    hanoi(n-1, B, A, C)
n = int(input())
print(2**n-1)

hanoi(n, 1,2,3)
