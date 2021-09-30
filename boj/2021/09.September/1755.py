M, N = map(int, input().split())
w = ["zero","one","two","three","four","five","six","seven","eight","nine"]
# 숫자를 영어로 바꾼 뒤, 사전 순 정렬하고, 다시 숫자로 바꿈
ans = list(map(lambda x: "".join(str(w.index(c)) for c in x.split()), sorted(map(lambda num: " ".join(w[int(c)] for c in num),(str(i) for i in range(M, N+1))))))
for row in (" ".join(ans[i*10:(i+1)*10]) for i in range((len(ans)+9)//10)):
    print(row)