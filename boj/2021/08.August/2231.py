N = int(input())
# 모든 경우의 수를 검사하면서
for i in range(1, N):
    # 분해합이 N 과 같다면 출력하고 종료
    if i + sum(map(int, str(i))) == N:
        print(i)
        break
# 분해합이 없으면 0 출력
else:
    print(0)