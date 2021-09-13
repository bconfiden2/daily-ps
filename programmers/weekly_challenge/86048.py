from itertools import combinations

def solution(enter, leave):
    N = len(enter)
    # set 으로 관리해서 중복 제거
    answer = [set() for i in range(N+1)]
    for out in leave:
        tmp = []
        # 이번 퇴실자가 퇴실하면서 만나는 사람들을 전부 모아서
        for i, v in enumerate(enter):
            if v != -1:
                tmp.append(v)
            if v == out:
                enter[i] = -1
                break
        # 만난 사람들(남아있던 사람들)은 서로 반드시 만남
        for v, u in combinations(tmp, 2):
            answer[v].add(u)
            answer[u].add(v)
    # 각 사람들이 만난 사람들의 수 반환
    return [len(s) for s in answer[1:]]