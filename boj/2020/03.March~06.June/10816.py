import sys
# 키(입력받은카드) : 값(카드갯수)
cards = {}
input()
for i in map(int, sys.stdin.readline().rstrip().split()) :
    # 입력받은 값이 현재 딕셔너리에 있으면 갯수 1 증가
    if i in cards :
        cards[i] += 1
    # 없으면 1개로 초기화
    else :
        cards[i] = 1
input()
for i in map(int, sys.stdin.readline().rstrip().split()) :
    # 카드에 값이 있으면 카드갯수 출력
    try :
        print(cards[i], end=' ')
    # 없으면 0
    except :
        print(0, end=' ')
