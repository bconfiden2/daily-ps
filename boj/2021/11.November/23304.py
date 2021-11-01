def aka(x):
    # 문자열 길이가 1이면 아카라카, 그 이상일 경우는 앞의 접미사가 아카라카인지 재귀적으로 확인
    return True if len(x)==1 else x==x[::-1] and aka(x[:len(x)//2])

# 입력받은 문자열이 akaraka 팰린드롬인지 확인
print("AKARAKA" if aka(input()) else "IPSELENTI")