N = int(input())
target = 1
for v in sorted(map(int, input().split())):
    if v > target:
        break
    target += v
print(target)