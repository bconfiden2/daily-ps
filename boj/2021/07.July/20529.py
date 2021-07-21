def distance(a, b, c):
    return sum(int(a[i]!=b[i]) + int(b[i]!=c[i]) + int(c[i]!=a[i]) for i in range(4))

T = int(input())
for _ in range(T):
    N = int(input())
    # 전체 사람들 중 MBTI 유형이 몇개씩 나왔는지 확인
    mbti = {}
    for m in input().split():
        mbti[m] = mbti.get(m, 0) + 1
    answer = -1

    sets = [[],[]]
    for key, val in mbti.items():
        # 만약 같은 MBTI 인 사람이 3명 이상 있을 경우, 무조건 0 을 뽑을 수 있음
        if val >= 3:
            answer = 0
        # 그 외로는 완전탐색을 통해 가장 가까운 거리를 갖는 세 사람을 구함
        else:
            sets[val-1].append(key)
            if val == 2:
                sets[0].append(key)

    if answer == 0:
        print(answer)
    else:
        # 모든 MBTI 에 대해 유형별로 하나씩 뽑아서 가능한 최소 거리를 구함
        tmp = [distance(sets[0][a], sets[0][b], sets[0][c]) for a in range(len(sets[0])-2) for b in range(a+1, len(sets[0])-1) for c in range(b+1, len(sets[0]))]
        # 만약 같은 MBTI 를 2명 이상 갖는 그룹이 없을 경우 == 모든 사람이 다른 MBTI 를 갖고 있는 경우이므로 그대로 최소값 출력
        if len(sets[1]) == 0:
            print(min(tmp))
        # 같은 MBTI 를 갖는 그룹이 있을 경우(ex. ISTJ,ISTJ,ENTP), 해당 그룹에서 2개를 뽑고 나머지 한 유형을 뽑는 경우의 수도 같이 고려
        else:
            print(min(tmp + [distance(a, a, c) for a in sets[1] for c in sets[0] if a!= c]))
                