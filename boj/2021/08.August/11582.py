N = int(input())
ch = list(map(int, input().split()))
k = int(input())
di = (N//k)

# k 명이 각각 자신이 맡은 부분을 정렬
for i in range(k):
    # 자신이 맡은 치킨집의 범위를 각자 정렬하여 출력
    for t in sorted(ch[i*di:(i+1)*di]):
        print(t, end=" ")
print()