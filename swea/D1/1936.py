a, b = map(int, input().split())
if a == 1 :
    if b == 3 :
        print('A')
    else :
        print('B')
else :
    if a - b == 1 :
        print('A')
    else :
        print('B')