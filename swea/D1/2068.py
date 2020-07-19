t = int(input())
for tc in range(t) :
    ans = max(list(map(int, input().split())))
    print("#{} {}".format(tc+1, ans))