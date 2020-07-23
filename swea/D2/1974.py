def check_sqaure(info) :                    # 사각형 9개 확인
    for x in range(3) :
        for y in range(3) :
            temp = []
            for r in range(3) :             # 각 사각형 안에 들어있는 값들이
                for c in range(3) :
                    temp.append(info[3*x + r][3*y + c])
            if len(set(temp)) != 9 :        # 중복되어있는게 있다면 False
                return False
    return True

def check_row(info) :                       # 9개 행이 맞는지 확인
    for i in range(9) :                     # 하나라도 중복된 값이 있다면 False 반환
        if len(set(info[i])) != 9 :
            return False
    return True

def check_column(info) :                    # 9개 열이 맞는지 확인
    for i in range(9) :
        temp = []
        for r in range(9) :
            temp.append(info[r][i])         # 열마다 데이터를 받아서
        if len(set(temp)) != 9 :            # 중복된 값이 있으면 False
            return False
    return True

t = int(input())
for tc in range(t) :
    able = False
    info = [list(map(int, input().split())) for i in range(9)]
    if check_row(info) and check_column(info) and check_sqaure(info):   
        able = True                         # 셋 중 하나라도 잘못된 값이 들어갈 경우는 False
    print("#{} {}".format(tc+1, int(able)))