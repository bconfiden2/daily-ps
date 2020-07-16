t = int(input())

for tc in range(t) :
    data = int(input())
    answer = 0
    if data % 2 == 0 :
        answer = data // 2 - data
    else :
        answer = data // 2 + 1
    print("#{} {}".format(tc+1, answer))