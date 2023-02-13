N, K = map(int, input().split())

# n부터 시작해서 그리디하게 K를 만들기
def make_K(n, arr):
    remain = K
    for i in range(n, 0, -1):
        arr[i] = remain // i
        remain = remain % i
    return remain == 0

for i in range(1, N):
    # arr[x] = K를 만드는 경우 x가 몇개 필요할지에 대한 리스트
    arr = [0 for _ in range(N)]
    # i부터 시작했을 때 K를 만드는게 가능하고,
    if make_K(i, arr) == True:
        # 필요한 자릿수가 N 이하일 경우
        maxi = max([0] + [i for i, v in enumerate(arr) if v!=0])
        if sum(arr) + maxi <= N:
            # 해당 조합을 정답으로 보고 출력
            ans = ""
            for i, v in enumerate(arr):
                if v != 0:
                    ans = "A"*v + ans
                if i == maxi:
                    break
                ans = "B" + ans
            print("B"*(N-len(ans)) + ans)
            exit()
print(-1)