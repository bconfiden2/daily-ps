t = int(input())
for tc in range(t) :
    a, b = map(int, input().split())
    ans = ''
    if a > b :
        ans = '>'
    elif a  < b :
        ans = '<'
    else :
        ans = '='
    print("#{} {}".format(tc+1, ans))
