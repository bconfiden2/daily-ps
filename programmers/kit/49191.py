def solution(n, results):
    # 플로이드 와샬을 사용하기 위한 행렬
    dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
    # 이기는 관계는 1로, 지는 관계는 -1 로 연결
    for r in results:
        dp[r[0]][r[1]] = 1
        dp[r[1]][r[0]] = -1
    for k in range(1, n+1):
        for r in range(1, n+1):
            for c in range(1, n+1):
                # r과 c가 k를 거쳐 비교 가능한 관계일 경우에 해당 관계를 그대로 가져감
                if dp[r][k] != 0 and dp[r][k] == dp[k][c]:
                    dp[r][c] = dp[r][k]
    # 각 노드마다 0인 관계(비교 불가능한)가 없는 노드의 개수를 반환
    return sum(1 for i in range(1, n+1) if sum(int(dp[i][j]==0) for j in range(1, n+1)) == 1)