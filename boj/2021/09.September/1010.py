for _ in range(int(input())):
    # 각 테스트케이스별로 mCn 구하기
    n, m = map(int, input().split())
    p, q = 1, 1
    for i in range(n):
        p *= (m-i)
        q *= (i+1)
    print(p // q)
