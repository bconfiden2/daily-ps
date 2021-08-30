def select(sz, cur, target, cnt):
    # 찾으려는 문자열일 경우
    if sz == len(target) and cur == target:
        return True, cnt
    # 5개를 다 뽑았다면 다음 재귀호출 x
    if sz == 5:
        return False, cnt
    # 각 자릿수마다 AEIOU 하나씩 뽑음
    for c in ('A','E','I','O','U'):
        # 뽑을때마다 카운트 증가시켜준뒤 재귀호출에 넣어줌
        cnt += 1
        # cnt 는 공유되어야 하기 때문에 반환받은 값으로 다시 갱신
        flg, cnt = select(sz+1, cur+c, target, cnt)
        # 만약 찾는 문자열일 경우 계속 flg 를 True 로 반환해서 쭉 빠져나감
        if flg:
            return True, cnt
    return False, cnt

def solution(word):
    return select(0, "", word, 0)[1]