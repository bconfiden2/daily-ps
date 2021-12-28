dp = [1 for i in range(int(input()))]
box = list(map(int, input().split()))
# 특정 인덱스 i 의 최대상자개수는
for i in range(len(box)):
    # 이전까지의 모든 최대상자개수들에서 이번에 상자를 넣었수 있을 때 가능한 최대값
    for j in range(i):
        if box[j] < box[i] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1
print(max(dp))