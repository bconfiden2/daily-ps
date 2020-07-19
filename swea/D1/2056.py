t = int(input())
max_day = [0,31,28,31,30,31,30,31,31,30,31,30,31]
for tc in range(t) :
    ans = -1
    date = input()
    month = int(date[4:6])
    day = int(date[6:])
    if 1 <= month and month <= 12 :
        if day <= max_day[month] :
            ans = date[:4] + "/" + date[4:6] + "/" + date[6:] 
    print("#{} {}".format(tc+1, ans))