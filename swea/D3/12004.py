# 두 수의 곱으로 표현되는 값들을 모두 저장해놓기
gu = set(a*b for a in range(1,10) for b in range(1,10))
for i in range(int(input())):
    print(f"#{i+1}", "Yes" if int(input()) in gu else "No")
