t = int(input())
for i in range(t) :
    nums = list(map(int, input().split()))
    print("#" + str(t + 1), round(sum(nums) / len(nums)))
