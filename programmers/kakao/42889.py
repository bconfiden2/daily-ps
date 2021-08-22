def solution(N, stages):
    # i번째 스테이지를 아직 클리어중인 플레이어의 수
    challenging = [0 for _ in range(N+2)]
    for val in stages:
        challenging[val] += 1
        
    # i번째 스테이지를 도달한 플레이어 수(클리어중인 사람 + 클리어한 사람)
    reached = [0 for _ in range(N+1)]
    # 뒤에서부터 누적합으로 구함
    cumsum = challenging[N+1]
    for idx in range(N, 0, -1):
        cumsum += challenging[idx]
        reached[idx] = cumsum
    
    # 위에서 구한 두 리스트를 기반으로 각 스테이지별 실패율을 구한 뒤
    answer = [c/r if r != 0 else 0 for c, r in zip(challenging, reached)]
    # 실패율을 기준으로 인덱스들을 정렬하고 0번째 인덱스 제외한 나머지 스테이지들 반환
    return [idx for idx, val in sorted(enumerate(answer), key=lambda x:x[1], reverse=True) if idx!=0]