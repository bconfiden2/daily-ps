N = int(input())
start = 1
while N // start != 1:  # i 번째 차리에 2**i 배수 값들만 남음
    start *= 2          # 남은 값의 개수가 1개인 2**i 값이 정담
print(start)