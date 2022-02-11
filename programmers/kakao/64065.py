def solution(s):
    answer = []
    include = set()
    # 들어온 문자열 s 에 들어있는 튜플 별로 나눈 뒤, 튜플의 길이를 기준으로 정렬하여 탐색
    for tp in sorted((map(lambda x: x[:-1], s[2:-1].split(",{"))), key=lambda x: len(x)):
        # 각 튜플 안에 있는 원소들 중 새로 추가되는 원소들을 순서대로 저장
        for v in tp.split(","):
            if v not in include:
                answer.append(int(v))
                include.add(v)
    return answer