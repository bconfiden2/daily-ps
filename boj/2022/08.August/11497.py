for _ in range(int(input())):
    N = int(input())
    L = sorted(map(int, input().split()))
    ans = max(L[1]-L[0], L[-1]-L[-2])
    for i in range(2, N):
        ans = max(ans, L[i]-L[i-2])
    print(ans)