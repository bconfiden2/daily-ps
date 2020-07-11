c = int(input())
for i in range(c) :
    scores = list(map(int, input().split()))
    n = scores[0]
    scores.remove(n)
    stu = 0
    avg = sum(scores) / len(scores)
    for i in scores :
        if i > avg :
            stu += 1
    print("%.3f%%"%(stu / n * 100))
