"""
n = 1000000

for a in range(2, n+1) :
    for i in range(2, int(a**0.5) + 1) :
        if a % i == 0 :
            break
    else :
        print(a)
"""

"""
n = 1000000
nums = [True] * (n+1)
nums[0] = nums[1] = False
for i in range(2, int(n**0.5)+1) :
    if nums[i] == True :
        for j in range(2, n//i + 1) :
            nums[i*j] = False

for i in range(2, n+1) :
    if nums[i] == True :
        print(i)
"""

import random
x = 4000
arr = list(range(x))
random.shuffle(arr)

print("start!")

#arr.sort()
for n in range(len(arr)) :
    for i in range(0,len(arr)-1 - n) :
        if arr[i] > arr[i+1] :
            temp = arr[i]
            arr[i] = arr[i+1]
            arr[i+1] = temp

print(arr)
