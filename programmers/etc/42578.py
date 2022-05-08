def solution(clothes):
    dt = {}
    for _, tp in clothes:
        dt[tp] = dt.get(tp, 0) + 1
    answer = 1
    # 의상의 종류별로 가능한 모든 조합
    for v in dt.values():
        answer *= (v+1)
    # 아무것도 안 입는 경우의 수 1 뺀 값 반환
    return answer-1