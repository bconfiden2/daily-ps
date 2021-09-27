def solution(sizes):
    # mw 는 최대 가로값, mh 는 최대 세로값
    mw, mh = 0, 0
    # 각 명함의 가로세로 중 작은 값을 가로로, 큰 값을 세로로 맞춰놓고 그들 중 최댓값이 mw, mh
    for a, b in sizes:
        mw, mh = max(mw, min(a,b)), max(mh, max(a,b))
    return mw * mh