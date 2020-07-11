n, k = map(int, input().split())
max = 0
for i in range(1, k+1) :
    data = int(str(n*i)[::-1])
    #print(type(int(data[::-1])))
    if data > max :
        max = data
print(max)