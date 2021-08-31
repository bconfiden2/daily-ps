def solution(numbers, hand):
    # 키패드 딕셔너리로 저장
    pad = {r+1:(r//3,r%3) for r in range(9)}
    pad[0] = (3,1)
    hand = 0 if hand=='left' else 1
    
    # 왼손은 0번째, 오른손은 1번째
    hpos = [(3,0), (3,2)]
    answer = ''
    for num in numbers:
        # (1,4,7)은 왼손, (3,6,9)는 오른손, 나머지 숫자들은 더 가까운 손으로
        curh = 0 if num in (1,4,7) else 1 if num in (3,6,9) else min([(sum(abs(pad[num][i] - hpos[h][i]) for i in range(2)), int(not h==hand), h) for h in range(2)])[2]
        # 해당 손의 위치 갱신
        hpos[curh] = pad[num]
        answer += str(curh)
        
    return "".join('L' if c=='0' else 'R' for c in answer)