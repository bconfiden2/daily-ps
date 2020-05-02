n = int(input())
for i in range(0,n-1) :
    print(' ' * i + '*' * (2*n-1 - 2*i))
print(' ' * (n-1) + '*')
for i in range(n-2,-1,-1) :
    print(' ' * i + '*' * (2*n-1 - 2*i))