line = input()
N = len(line)
start, end = 0, min(10, N)
for i in range((N-1)//10+1):
    print(line[start:end])
    start, end = end, min(end+10, N)
