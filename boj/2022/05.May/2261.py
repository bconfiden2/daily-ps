dist = lambda x,y: (x[0]-y[0])**2 + (x[1]-y[1])**2

def find(L, R):
    # 구역을 반반 분할해나갈때 가능한 최소 영역 크기
    if R - L <= 3:
        return min(dist(P[i],P[j]) for i in range(L, R) for j in range(i+1, R))
    # 중앙선 기준 좌/우측 영역 각각에서의 최소 거리
    M = (L + R) // 2
    ans = min(find(L, M), find(M, R))
    # 좌측-우측 을 연결할 때 최소 거리를 갱신 가능한 점들
    C = sorted((P[i] for i in range(L, R) if (P[i][0]-P[M][0])**2 < ans), key=lambda x:x[1])
    for i in range(len(C)):
        for j in range(i+1, len(C)):
            if (C[i][1]-C[j][1])**2 >= ans: break
            ans = min(ans, dist(C[i],C[j]))
    return ans

import sys
N = int(input())
# 좌표들을 X 기준으로 정렬해놓고 분할정복
P = sorted(tuple(map(int, line.split())) for line in sys.stdin)
print(find(0, N))
