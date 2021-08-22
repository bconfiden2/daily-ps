import sys
N, M = map(int, input().split())
A = sorted([int(line) for line in sys.stdin])

# 두 수를 골랐을 때 M 보다 큰 차이들 중 가장 작은 차이값을 반환 
def tp(ldx, rdx, arr, M):
    # tmp(반환값) 초기화는 가장 큰 차이값으로 설정
    tmp = arr[-1] - arr[ldx]
    while True:
        cur = arr[rdx] - arr[ldx]
        # 만약 현재 두 수의 차이가 M 보다 크면, ldx 를 땡겨서 차이를 줄임
        if cur > M:
            # 인덱스를 옮기기 전에, 해당 차이값과 최소값 비교하여 갱신
            if cur < tmp:
                tmp = cur
            ldx += 1
        # M 보다 작으면, rdx 를 밀어서 차이를 늘림
        elif cur < M:
            # 만약 rdx 가 끝에 있는 상태라면 더 볼 필요 없으므로 종료
            if rdx == N-1:
                break
            rdx += 1
        else:
            return M
    return tmp

# N 이 1이면 반드시 M 이 0이 되어야 하므로, M 값에 대해서만 예외처리
print(0 if M==0 else tp(0, 1, A, M))