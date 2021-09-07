def solution(weights, head2head):
    # 전체 승률(W 의 횟수 / 경기 수)
    wins = []
    for val in head2head:
        total = w = 0
        for c in val:
            if c == 'W':
                w += 1
            if c != 'N':
                total += 1
        wins.append((w/total) if total > 0 else 0)
    # 무거운 복서를 이긴 횟수
    mbeh = (sum(1 if (weights[you] > weights[me]) else 0 for you, c in enumerate(val) if c=='W') for me, val in enumerate(head2head))
    # (승률, 무복이횟, 몸무게, -번호)
    answer = [(a,b,c,-idx-1) for idx, (a,b,c) in enumerate(zip(wins, mbeh, weights))]
    return [-d for a,b,c,d in sorted(answer, reverse=True)]