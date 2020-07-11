import sys
# 회사에 있는 사람 목록 딕셔너리
company = {}
for i in range(int(input())) :
    # 한 줄을 읽어서 이름과 출입상태로 나눈다
    name, stat = sys.stdin.readline().rstrip().split()
    # 출근이라면 회사딕셔너리에 사람 추가
    if stat == 'enter' :
        company[name] = 1
    # 퇴근이라면 회사딕셔너리에서 그 사람 제거
    else :
        del company[name]
# 회사에있는 사람을 역순으로 정렬한 후 각각 개행문자 붙여서 출력한다
print('\n'.join(sorted(company, reverse=True)))
