t = int(input())
for tc in range(t) :
    time = list(map(int, input().split()))
    hour = time[0] + time[2]
    minute = time[1] + time[3]
    if minute >= 60 :
        minute -= 60
        hour += 1
    if hour > 12 :
        hour -= 12
    print("#{} {} {}".format(tc, hour, minute))