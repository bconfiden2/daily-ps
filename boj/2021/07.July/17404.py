import sys
N = int(input())
colors = [[0,0,0]] + [list(map(int, line.strip().split())) for line in sys.stdin]

if N == 2:
    print(min(colors[1][c1] + colors[2][c2] for c1 in range(3) for c2 in range(3) if c1 != c2))
else:
    points = [(0,1),(0,2),(1,0),(1,2),(2,0),(2,1)]      # 1번 집과 N번 집에 대한 제약을 미리 걸어두고 탐색
    answer = 10e9
    for begin, end in points:                           # 모든 조합을 탐색하면서 나머지 집들에 대해서는 DP 로 최소값 찾음
        dp = [[0,0,0] for i in range(N+1)]
        dp[1][begin] = colors[1][begin]                 # dp 배열에서 1번 집의 값은 미리 정해둔 색깔로만 칠해놓음
        for i in range(2, N):                           # 2번부터 N-1번 집까지 DP 채우기
            for c in range(3):
                lst = [dp[i-1][c2] for c2 in range(3) if (c2 != c and dp[i-1][c2] != 0)]            # 이전 집과 연속된 색깔이 아니며, 이전 집을 칠할 수 있었을 경우에만
                dp[i][c] = (min(lst) + colors[i][c]) if len(lst) else 0                             # DP 배열값이 0 이라는 것은 불가능한 경로라는 뜻
        tmp = min(dp[N-1][i] for i in range(3) if (i != end and dp[N-1][i] != 0)) + colors[N][end]  # 마지막 N 번 집의 색깔 칠해주고 최소값 갱신
        if tmp < answer:
            answer = tmp
    print(answer)