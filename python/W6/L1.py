# 자카드 지수
allSet = [{1,2,3,4,5,6,7,8,9,10}, {1,3,5,7,12,15}, {3,12,15,18,20}, {12,13,14,15,16,17,18,19}]

for a in allSet :
    for b in allSet :
        intersect = len(a & b)
        union = len(a | b)
        jaccard = intersect / union
        print(jaccard)
