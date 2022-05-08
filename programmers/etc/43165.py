# 백트래킹으로 가능한 모든 경우의 수 탐색
def bt(arr, T, idx, total):
    # 마지막에 도달했을 경우, 현재 조합으로 만들어진 수와 타겟과 비교
    if idx == len(arr):
        return int(total == T)
    # 그 외에는 자기 위치에서 + 로 간 경우와 - 로 간 경우를 검사하여 두 경우의 수를 합
    return bt(arr,T,idx+1,total+arr[idx]) + bt(arr,T,idx+1,total-arr[idx])

def solution(n, T):
    return bt(n, T, 0, 0)