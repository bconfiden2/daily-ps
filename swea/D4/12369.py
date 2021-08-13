for t in range(1, int(input())+1):
    candi, target = input().split()
    target = int(target)
    # 알파벳 순서대로 사용하기 때문에 문자 집합을 정렬해놓음
    candi, L = sorted(candi), len(candi)

    # 문자가 1개일 때는 따로 처리
    if L==1:
        print("#{} {}".format(t, candi[0]*target))
        continue
    digit, tmp = 1, L
    # 예상되는 N번째 일련번호의 자릿수를 구해놓음
    while True:
        digit += 1
        if tmp + L**(digit) >= target:
            break
        tmp += L**digit

    # answer 에 들어갈 자릿수를 하나씩 채워나감
    answer = ""
    for i in range(digit-1, -1, -1):
        idx = 0
        # 앞서서 문자들을 정렬해놓았기 때문에, 이번 자리에 어떤 문자가 들어갈지 예측 가능
        while tmp + L**i < target:
            tmp += L**i
            idx += 1
        answer += candi[idx]

    print(f"#{t} {answer}")