# 이번 팰린드롬 문자열이 입력받은 문자열보다 크면 출력 후 종료
def check(num, N):
    sz = len(num) // 2
    left, mid, right = num[:sz], num[sz:-sz], num[-sz:]
    flip = left + mid + left[::-1]
    if int(flip) > int(N):
        print(flip)
        exit()

N = input()
# 한자리수일 경우는 바로 다음 값 출력 후 종료
if len(N) == 1:
    if int(N) == 9: print(11)
    else: print(int(N)+1)
    exit()
# 시작한 수에서 곧바로 다음 팰린드롬을 만들 수 있는지 검사
check(N, N)
target, right = N[:-(len(N)//2)], N[-(len(N)//2):]
# 이후에는 문자열의 중간에 있는 값부터 1씩 올려가며 확인
while True:
    target = str(int(target)+1)
    check(target + right, N)