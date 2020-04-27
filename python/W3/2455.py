max = 0
total = 0
for i in range(0,4) :
    off, on = map(int, input().split())
    total += on
    total -= off
    if total >= max :
        max = total
print(max)
