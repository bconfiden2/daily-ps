N = int(input())

# 현재 Moo 수열에서 찾을 n 번째 글자와, 수열의 길이, 몇번째 수열인지
def reverse_moo(n, total, depth):
    # 0번째 Moo 수열 (== "m o o") 일 경우, 알맞은 글자 출력하고 리턴
    if depth == 0:
        print('m' if n==1 else 'o')
        return
    # 현재 Moo 수열을 3 구간으로 나눔
    section = (total - (3+depth)) // 2
    # 앞쪽 S(i-1) 구간
    if n <= section:
        # 글자 위치는 그대로 주고, S(i-1) 번째 Moo 수열에서 해당 위치 재귀 탐색
        reverse_moo(n, section, depth-1)
    # 이번 수열의 m o ... o 구간
    elif n <= section+(3+depth):
        # 첫 글자일 경우에만 m 출력하고 나머지는 o 출력한 뒤 종료
        print('m' if n==section+1 else 'o')
        return
    # 뒤쪽 S(i-1) 구간
    else:
        # S(i-1) 번째에서 Moo 수열에 맞게 위치 조정해주고 다시 재귀적으로 탐색
        reverse_moo(n-(section+(3+depth)), section, depth-1)

# 입력값 N 이 몇번째 Moo 수열에 들어가있는지 구해서
i,cnt = 0,0
while cnt <= N:
    cnt = cnt*2 + (3+i)
    i += 1
# 재귀호출 시작
reverse_moo(N, cnt, i-1)