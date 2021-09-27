n = int(input())
wins = sorted(map(int, input().split()))
# 승점이 낮은 팀부터 차근차근 돌면서
for _ in range(n-1):
    # 만약 승점이 음수로 떨어져있거나 남은 팀의 수보다 승점이 더 높을 경우 불가능
    if wins[0] < 0 or wins[0] > len(wins)-1:
        print(-1)
        break
    # 현재 팀이 진 횟수만큼, 승점이 높은 팀들부터 차례대로 자기가 이겼다고 처리
    for j in range(1+wins[0], len(wins)):
        wins[j] -= 1
    # 승점 갱신된 남은 팀들을 다시 정렬 후 반복
    wins = sorted(wins[1:])
else:
    print(1 if wins[0] == 0 else -1)