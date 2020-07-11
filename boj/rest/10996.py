n = int(input())

if n == 1 :
    print('*')
else :
    for i in range(n) :
        for i in range(1,3) :
            for j in range(1,n+1) :
                if(i%2 == j%2) :
                    print('*', end='')
                else :
                    print(' ', end='')
            print()