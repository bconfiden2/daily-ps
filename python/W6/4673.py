# 딕셔너리 키(해당숫자) : 깂(셀프넘버 여부)
f = {i:0 for i in range(1,10001)}
# 숫자 + 각 자릿수의 합을 구해주는 함수
def calc(i) :
    ans = i
    temp = str(i)
    for k in range(len(temp)) :
        ans += int(temp[k])
    return ans
# 딕셔너리에서 해당 셀프넘버를 지워주는 함수, 10000 전까지 재귀적으로 호출됨
def erase(i) :
    if i > 10000 :
        return
    else :
        temp = calc(i)
        f[temp] = 1
        erase(temp)
# erase 를 재귀적으로 호출하기 때문에 실제로는 만번보다 훨씬 적게 함수가 호출됨
for i in range(1,10001) :
    if f[i] == 0 :
        erase(i)
        print(i)
