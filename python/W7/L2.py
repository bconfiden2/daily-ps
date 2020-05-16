# 유클리드 알고리즘 재귀함수
'''
def gcd(x, y) :
    if y == 0 : return x
    return gcd(y, x % y)

print(gcd(32, 24))
'''

# 피보나치 수열
'''
memo = {}

def fib(n) :
    if n == 0 : return 0
    elif n == 1 : return 1;
    if n in memo : return memo[n]
    ret fib(n-1) + fib(n-2)
    memo[n] = ret
    return ret

print(fib(8))
'''

# 하노이의 탑
def hanoi(n, A, B, C) :
    if n == 1 :
        print("%d %d"%(A, C))
        return 1
    return hanoi(n-1, A, C, B) + hanoi(1, A, B, C) + hanoi(n-1, B, A, C)
print(2**(n-1))
print(hanoi(3, 1,2,3))
