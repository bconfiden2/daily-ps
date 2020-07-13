t = int(input())

def printline(before, n) :
    if n == N + 1 :                 # 마지막 줄까지 출력 후에 종료
        return
    lines = [0]                     # 이번 줄의 정보에 대한 리스트 (양 끝에 0 추가)
    for i in range(len(before) - 1) :   # 윗줄을 보며 정보 채우기
        lines.append(before[i] + before[i+1])
    lines.append(0)
    for i in lines[1:n+1] :         # 이번 줄을 0 빼고 출력
        print(i, end=' ')
    print()
    printline(lines, n+1)           # 다음 줄 재귀호출

for tc in range(t) :                
    global N                        # 입력받을 n 을 전역변수로 둔다
    N = int(input())
    print("#" + str(tc+1))
    print(1)                        # 첫번째 줄 1 출력 후
    printline([0,1,0], 2)           # 두번째 줄 부터 재귀호출 (각 라인의 양 끝에 0 을 추가)