import sys
N = int(input())
# 전체 로프들을 오름차순 정렬한 뒤 순서대로 탐색
# 
print(max(v*(N-i) for i,v in enumerate(sorted(int(v) for v in sys.stdin))))