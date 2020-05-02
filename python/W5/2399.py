n = int(input())
points = list(map(int, input().split()))
points.sort()

sum = 0
for i in range(0, n//2) :
    sum += (points[n-1 - i] - points[i]) * ((n - 1) - 2*i)

print(sum * 2)




#       b - a  c - a  d - a  e - a
#b - a         c - b  d - b  e - b
#c - a  c - b         d - c  e - c
#d - a  d - b  d - c         e - d
#e - a  e - b  e - c  e - d
#f - a  f - b  f - c  f - d  f - e
