N = int(input())
# 꼭짓점들을 차례대로 나열하고, 마지막에 첫 꼭짓점 추가
p = [tuple(map(int, input().split())) for i in range(N)]
p = p + [p[0]]
# 다각형의 면적 구하는 공식
print(abs(round(sum(p[i][0]*p[i+1][1]-p[i][1]*p[i+1][0] for i in range(N))/2, 1)))
