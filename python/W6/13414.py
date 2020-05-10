import sys
import operator
k, l = map(int, input().split())
lists = {}
# 입력받는 애들을 딕셔너리에 넣어준다. 키(학번):값(인덱스번호)
for i in range(l) :
    call = sys.stdin.readline().rstrip()
    lists[call] = i
# 딕셔너리를 값 기준으로 정렬한다. 앞에 남아있는 사람들이 됨
slists = sorted(lists.items(), key=operator.itemgetter(1))
# 정렬된 딕셔너리에서 학번을 k번 출력한다
fk = 0
for i in slists :
    print(i[0])
    fk += 1
    if fk == k :
        break
