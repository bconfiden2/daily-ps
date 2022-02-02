import sys
N, arr = input(), sorted(int(v) for v in sys.stdin)
# 뒤에서부터 탐색함으로써 가능한 높은 가격의 물건들을 최대한 많이 공짜로 받아내기
print(sum(arr[i]+(arr[i-1] if i>=1 else 0) for i in range(int(N)-1, -1, -3)))