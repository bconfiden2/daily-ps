import re

def solution(new_id):
    ## 1단계. 대문자를 소문자로 치환
    new_id = new_id.lower()
    
    ## 2단계. 규칙에 맞는 문자 이외의 문자들 제거
    new_id = re.sub("[^a-z0-9-_.]", "", new_id)
    
    ## 3단계. 아이디에 존재하는 .. 들 . 으로 치환
    new_id = re.sub("[.]+", ".", new_id)
    
    ## 4단계. 양끝의 . 제거
    if len(new_id) > 0 and new_id[0] == '.':
        new_id = new_id[1:]
    if len(new_id) > 0 and new_id[-1] == '.':
        new_id = new_id[:-1]
    
    ## 5단계. 빈 문자열 여부 확인
    if len(new_id) == 0:
        new_id = 'a'
    
    ## 6단계.
    if len(new_id) >= 16:
        new_id = new_id[:15]
        if new_id[-1] == '.':
            new_id = new_id[:-1]
    
    ## 7단계. 마지막 글자로 아이디 길이 맞추기
    while len(new_id) < 3:
        new_id += new_id[-1]
    return new_id