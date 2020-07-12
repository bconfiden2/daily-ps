n = int(input())
clap = [3, 6, 9]

for p in range(1, n+1) :
    cnt = 0
    for i in range(3) :                     # 최대 1000 까지니 세자릿수만 다 검사
        digit = p % (10**(i+1)) // (10**i)  # 백의 자리, 십의 자리, 일의 자릿수
        if digit in clap :                  # 해당 자릿수가 3, 6, 9 이면 박수 + 1
            cnt += 1
    if cnt == 0 :                           # 3 6 9 가 하나도 없으면 값 출력
        print(p, end = ' ')
    else :                                  # 그 외엔 박수 횟수만큼 출력
        print('-' * cnt, end = ' ')
