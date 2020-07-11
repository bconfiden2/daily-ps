# 들어온 세자릿수의 수에 대해서 등차수열인지 검사
def hansoo(i) :
    soo = str(i)
    if int(soo[0]) - int(soo[1]) == int(soo[1]) - int(soo[2]) :
        return True

n = int(input())
# 두자릿수까지는 모두 등차수열이므로 바로 출력
if n < 100 :
    print(n)
# 100보다 큰 경우 세자릿수들만 등차수열 계산한지 99 개 더해서 출력
else :
    # 네자릿수는 하나밖에 없으니 제외
    count = 0
    if n == 1000 :
        n = 999
    for i in range(100, n+1) :
        if hansoo(i) :
            count += 1
    print(count + 99)
