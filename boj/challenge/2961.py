n = int(input())
s = []
# 재료 하나를 한 쌍으로써 리스트에 추가한다
for i in range(n) :
    s.append(list(map(int, input().split())))
# 모든 부분집합을 돌며 차이를 저장할 공간
ans = []

# slist 의 모든 부분집합을 재귀적으로 돌기
def count(sv, ssv, slist, len) :
    global ans
    if len == 0:
        return;
    else :
        for i in range(len) :
            # 자기 자신 추가
            ans.append(abs((slist[i][0] * sv) - (slist[i][1] + ssv)))
            # 자기 아래에 종속되어있는 애들을 또 추가
            count(slist[i][0] * sv , slist[i][1] + ssv, slist[i+1:], len-i-1)

# 돌려주면 ans 에 부분집합의 값들이 저장됨
count(1, 0, s, n)
# 최솟값 출력
print(min(ans))

# 그림으로 그려보면 다음과 같다
# 1 - 2 - 3 - 4 - 5
#           - 5
#       - 4 - 5
#       - 5
# 1 - 3 - 4
#       - 5
# 1 - 4 - 5
# 1 - 5

# 2 - 3 - 4 - 5
#       - 5
#   - 4 - 5
#   - 5

# ...
