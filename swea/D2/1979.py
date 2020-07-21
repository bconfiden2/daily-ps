t = int(input())
for tc in range(t) :
    n, k = map(int, input().split())
    num = 0
    maps = []
    for i in range(n) :
        maps.append(list(map(int, input().split())))
    for row in maps :
        for i in range(n) :
            if i - 1 >= 0 and row[i-1] == 0 :
                if i + 1 < n and i + 2 < n :
                    if row[i] == 1 and row[i+1] == 1 and row[i+2] == 1 :
                        if row[i+1] == 0 or i + 1 >= n :
                            num += 1
    for j in range(n) :
        for i in range(n) :
            if i - 1 >= 0 or row[i-1][j] == 0 :
                if i + 1 < n and i + 2 < n :
                    if row[i][j] == 1 and row[i+1][j] == 1 and row[i+2][j] == 1 :
                        if row[i+1][j] == 0 or i + 1 >= n :
                            num += 1
    print("#{} {}".format(tc+1, num))