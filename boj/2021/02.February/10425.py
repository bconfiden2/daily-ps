import sys

T = input()

fib = {}
fib[0] = bef2 = 0
fib[1] = bef1 = 1

for i in range(2, 100001):
    val = str(bef2 + bef1)[-21:]    # n 번째 피보나치의 마지막 20자리를 키로 해서
    fib[val] = i                    # n 을 값으로 넣음
    bef2 = bef1                     # 다음 피보나치 업데이트
    bef1 = int(val)

for line in sys.stdin:
    print(fib[line.strip()[-21:]])  # 입력받은 피보나치값의 마지막 20자리로 n 을 구함
