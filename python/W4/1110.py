n = int(input())
data = -1
temp = n
cycle = 0
while(n != data) :
    data = 10 * (temp % 10) + (temp // 10 + temp % 10) % 10
    temp = data
    cycle += 1

print(cycle)