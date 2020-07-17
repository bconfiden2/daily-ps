t = int(input())

for tc in range(t) :
    numbers = list(map(int, input().split()))
    print("#{} {}".format(tc+1, int(round((sum(numbers) - max(numbers) - min(numbers)) / (len(numbers) - 2), 0))))