n, m = map(int, input().split())
mat = [[int(c) for c in input()] for i in range(n)]
answer = -1

# 제곱수인지 확인하는 함수
def is_squared(x):
    return (int(int(x**0.5+0.1)**2) == x) if hex(x)[-1] in ('0','1','4','9') else False

# 설정한 조건에 맞게 재귀호출로 값 만들어주는 함수
def select(cur_size, target_size, r, c, dr, dc):
    value = mat[r][c]
    # 설정한 수열 크기를 채웠을 경우 마지막 자리 반환
    if cur_size == target_size:
        return value
    nr, nc = r+dr, c+dc
    # 등차수열을 이루는 다음 위치가 인덱스를 벗어날 경우 불가능
    if nr < 0 or nr >= n or nc < 0 or nc >= m:
        return 2
    # 다음 등차수열 위치로 이동
    tmp = select(cur_size+1, target_size, nr, nc, dr, dc)
    # 불가능한 수열(2) 일 경우 그대로 불가능 처리, 가능한 수열이면 문자열로 한자리씩 차근차근 쌓아서 값 완성
    return 2 if tmp == 2 else (str(value) + str(tmp))

# 완전탐색으로 만들 수 있는 모든 조합을 탐색
for size in range(1, max(n,m)+1):
    for r in range(n):
        for c in range(m):
            # 행과 열 인덱스가 등차수열을 이루기 위한 차이값들
            for dr in range(-n+1, n):
                for dc in range(-m+1, m):
                    # 수열의 길이가 1일 때는 dr과 dc가 0 이어도 상관 없음
                    if (dr != 0 or dc != 0) or size == 1:
                        # 조건에 맞는 값을 찾은 뒤
                        tmp = int(select(1, size, r, c, dr, dc))
                        # 제곱수일 경우 최대값 갱신
                        if is_squared(tmp):
                            if tmp > answer:
                                answer = tmp

# 최대값 출력
print(answer)