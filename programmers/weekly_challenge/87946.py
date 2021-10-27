from itertools import permutations

# 특정 순서대로 돌았을 떄 탐험 가능한 던전 수 반환
def value(k, dg, order):
    cnt = 0
    for i in order:
        if k < dg[i][0]:
            break
        cnt += 1
        k -= dg[i][1]
    return cnt
        
def solution(k, dg):
    # 던전 개수는 최대 8 이므로 모든 경우를 탐색해봐도 최대 8!번이므로, 전부 돌아서 최대 던전 수 구하기
    return max(value(k, dg, order) for order in permutations(range(len(dg))))