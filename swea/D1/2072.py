t = int(input())
for tc in range(1, t + 1) :
    number = list(map(int, input().split()))
    all = 0
    for i in range(len(number)) :
        if number[i] % 2 == 1 :
            all += number[i]
    print("#" + str(tc), all)