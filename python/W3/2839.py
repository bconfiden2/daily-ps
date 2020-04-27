N = int(input())
five = 0
three = 0
if N % 5 == 0 :
    five = N // 5
elif N % 5 == 1 :
    three = 2
    five = (N-6) // 5
elif N % 5 == 2 :
    three = 4
    five = (N - 12) // 5
elif N % 5 == 3 :
    three = 1
    five = (N - 3) // 5
elif N % 5 == 4 :
    three = 3
    five = (N - 9) // 5

if N == 4 or N == 7 :
    print(-1)
else :
    print(five + three)
