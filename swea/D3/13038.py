for t in range(int(input())):
    n = int(input())
    info = ("".join(input().split()))*2
    tot = sum(map(int, info))//2
    # 일주일에 있는 수업일수 만큼 최대한 채워놓음
    w = (n//tot-(1 if n%tot==0 else 0))
    m = 7
    # 나머지 횟수를 채울때, 무슨 요일을 시작으로 할지
    for i,v in enumerate(info[:7]):
        if v=="0": continue
        cnt, day = 0, 0
        for x in info[i:i+7]:
            cnt += 1 if x=="1" else 0
            day += 1
            if cnt == n-w*tot:
                break
        m = min(m, day)
    print(f"#{t+1} {w*7+m}")