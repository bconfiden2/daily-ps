def solution(price, money, count):
    # 등차수열의 합으로 필요한 금액 구하기
    answer = money - price * (count*(count+1)//2)
    return 0 if answer > 0 else -answer