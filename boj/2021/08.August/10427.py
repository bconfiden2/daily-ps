for _ in range(int(input())):
    line = input().split()
    N = int(line[0])
    # 리스트를 정렬해서 저장, 정렬한 상태이기 때문에 앞에서부터 i개씩 묶어 확인하면서 그 차이가 가장 작은 i개가 S(i) 값이 됨.
    A = sorted(list(map(int, line[1:])))
    # 원소별 차이값을 저장, 누적합을 구하기 쉽게 역순으로 저장
    diff_r = [A[i+1]-A[i] for i in range(N-1)][-1::-1]    
    answer = 0
    
    # S(i) 구하기, (number = i - 1)
    for number in range(1, N):
        # 처음에 number 개의 차이값들로 초기화한 뒤 탐색 시작
        section = tmp = cumsum = 0
        for i in range(0, number):
            section += diff_r[i]
            cumsum += section
            tmp += section
        # 처음 number개 그룹으로 초기화했으니, 그 다음 number개의 그룹부터 확인, 같은 방식으로 끝까지 선형탐색
        for i in range(1, N-number):
            # 이번 number개 그룹의 S 값은, 매번 해당 구간을 다 더할 필요 없이 누적값을 통해 관리 가능
            section = section - diff_r[i-1] + diff_r[i+number-1]
            cumsum = cumsum + section - number * diff_r[i-1]
            # number개 그룹들의 S 값들 중 가장 작은 값을 tmp 에 저장
            if cumsum < tmp:
                tmp = cumsum
        # S(i) 값이 tmp 에 저장돼있으므로 전부 더해줌
        answer += tmp
    print(answer)