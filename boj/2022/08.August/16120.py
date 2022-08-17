i = P = 0
target = input()
while i < len(target):
    c = target[i]
    # 앞에서부터 문자 하나씩 검사해나가는데, A가 나올 경우 PPAP 문자열인지 확인
    if c == 'A':
        # 이전에 P가 최소 2개 이상 등장했고, 다음 문자도 P인 경우
        if P >= 2 and i < len(target)-1 and target[i+1] == 'P':
            # PPAP 를 P 로 변환
            P -= 1
            i += 2
        # 조건을 만족시키지 못할 경우 PPAP 문자열이 아님
        else:
            print("NP")
            break
    else:
        P += 1
        i += 1
else:
    # 전부 변환되고 마지막에 P 하나만 남아있어야 PPAP 문자열
    if P == 1:
        print("PPAP")
    else:
        print("NP")