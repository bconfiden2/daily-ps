t = int(input())
for tc in range(t) :
    a, b = map(int, input().split())
    print("#{} {} {}".format(tc+1, a//b, a%b))