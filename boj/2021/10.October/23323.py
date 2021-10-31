for _ in range(int(input())):
    n, m = map(int, input().split())
    cnt = 1
    while n > 1:
        n //= 2
        cnt += 1
    print(cnt + m)