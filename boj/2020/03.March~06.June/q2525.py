hour, minute = map(int, input().split())
work = int(input())

time = 60 * hour + minute + work

print(time // 60 % 24, time % 60)
