t = int(input())

for tc in range(t) :
    n = int(input())
    prices = list(map(int, input().split()))
    ans = 0
    max = 0
    for i in range(n-1,-1,-1) :
        if prices[i] > max :
            max = prices[i]
        ans += max - prices[i]

    print("#" + str(tc+1), ans)