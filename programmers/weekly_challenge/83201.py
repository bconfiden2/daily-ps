def grade(score):
    if score >= 90:
        return 'A'
    elif score >= 80:
        return 'B'
    elif score >= 70:
        return 'C'
    elif score >= 50:
        return 'D'
    else:
        return 'F'

def solution(scores):
    N = len(scores)
    my_score = [[scores[r][c] for r in range(N)] for c in range(N)]
    score = []
    for idx, row in enumerate(my_score):
        # 최소/최대값이 몇 개 있는지 확인하기 위한 딕셔너리
        sc = {}
        for v in row:
            sc[v] = sc.get(v, 0) + 1
        # 만약 내가 매긴 나의 성적이 최대값 혹은 최소값에 속하고 해당 값이 한개만 있을 때는 평균에서 제외
        if row[idx] in (min(row), max(row)) and sc[row[idx]] == 1:
            score.append((sum(row)-row[idx])/(N-1))
        # 아니면 그냥 평균에 포함시킴
        else:
            score.append(sum(row)/N)
    return "".join(grade(s) for s in score)