def solution(picks, minerals):
    tmp = {'diamond':0,'iron':1,'stone':2}
    # 입력으로 들어온 캐야하는 광물들을 5개 단위로 잘라내고, 최대 곡괭이 수만큼만 덩어리 유지
    chunks = [list(map(lambda x:tmp[x], minerals[i:i+5])) for i in range(0,len(minerals),5)][:sum(picks)]
    # 각 덩어리에 대해서 곡괭이별로 소모되는 피로감을 계산하고, 내림차순으로 정렬
    dp = sorted([[sum(map(lambda x: 5**max(mat-x,0), chunk)) for mat in range(3)] for chunk in chunks], key=lambda x:x[2], reverse=True)
    
    # 피로감이 큰 덩어리부터 다이아몬드 - 철 - 돌 곡괭이 순으로 캐버림
    d,i,s = picks
    answer = 0
    answer += sum(row[0] for row in dp[:d])
    answer += sum(row[1] for row in dp[d:d+i])
    answer += sum(row[2] for row in dp[d+i:])
    return answer