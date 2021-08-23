def solution(table, languages, preference):
    jobs = {c.split()[0]:c.split()[1:] for c in table}

    maxi, answer = 0, ''
    # 직업군 이름 순서대로 검사
    for job in sorted(jobs.keys()):
        val = 0
        # val = 입력으로 받은 개발자 언어들의 (선호도 * 점수)의 총합
        for lang, pref in zip(languages, preference):
            score = 0 if lang not in jobs[job] else (5-jobs[job].index(lang))
            val += pref * score
        # 최대값을 갖는 직업군을 갱신
        if val > maxi:
            maxi = val
            answer = job

    return answer