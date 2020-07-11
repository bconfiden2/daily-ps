k = int(input())
num = []
for i in range(k) :
    a = int(input())
    if a == 0 :
        num.pop()
    else :
        num.append(a)

print(sum(num))
