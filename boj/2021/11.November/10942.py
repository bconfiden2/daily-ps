import sys
N, arr, M = int(input()), list(map(int, input().split())), int(input())
palin = [set() for _ in range(N)]

# 두개의 포인터를 팰린드롬이 성립되지 않을때까지 양쪽으로 넓혀감
def check(ldx, rdx):
    while True:
        if arr[ldx] != arr[rdx]:
            return
        palin[ldx].add(rdx)
        if ldx-1 < 0 or rdx+1 >= N:
            return
        ldx -= 1
        rdx += 1

# 각 위치마다 어떤 인덱스까지가 팰린드롬인지 미리 전부 체크해놓음
for s in range(N):
    check(s, s)
    if s < N-1 and arr[s] == arr[s+1]:
        check(s, s+1)

# 들어오는 입력에 대해서는 s,e 가 팰린드롬인지 확인만 해서 출력
for line in sys.stdin:
    s, e = map(int, line.split())
    print(int(e-1 in palin[s-1]))