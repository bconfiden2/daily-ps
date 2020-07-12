t = int(input())

for tc in range(1, t + 1) :
    ans = 0
    line = input()
    for i in range(1, 11) :                 # 마디의 갯수 1개~10개 까지 전부 검사
        for j in range(30 // i - 1) :       # 각 마디 갯수 별로 1 부터 30 까지 반복이 되는지 확인
            if line[i*j:i*(j+1)] != line[i*(j+1):i*(j+2)] : # 슬라이싱해서 하나라도 다른게 있으면 컷
                break
        else :                              # 전부 통과됐을 경우 답으로 지정하고 종료
            ans = i
            break
    print("#{} {}".format(tc, ans))