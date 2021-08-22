from itertools import combinations

# 특정 메뉴(target)가 전체 고객주문들 중에 몇번 존재하는지 반환
def check(target, orders):
    cnt = 0
    for order in orders:
        for t in target:
            if t not in order:
                break
        else:
            cnt += 1
    return cnt

# course로 들어온 조합될 메뉴의 수 마다 탐색 실시
def course_traversal(bef, cur, candidates, menu_set, orders):
    # candi 에는 (횟수, 메뉴이름)
    candi = []
    
    # 이전 탐색에서 2개 이상 나왔던 메뉴들에 대해서만 검사
    for menu in candidates:
        # 백트래킹(조합에서 뽑을 때 제외시키기 위해)
        for m in menu:
            menu_set.remove(m)
        # 뽑을 수 있는 메뉴들 중에 새롭게 추가되어야 하는 메뉴의 수만큼 메뉴를 새로 뽑음
        for comb in combinations(menu_set, cur-bef):
            # 이전에 뽑았던 메뉴에다가 새로 뽑은 메뉴들 더해서
            test_menu = menu+"".join(comb)
            # 해당 메뉴가 주문이 몇번 있었는지 확인해서
            flg = check(test_menu, orders)
            # 주문이 2번 이상 존재했으면 후보에 넣어줌
            if flg >= 2:
                candi.append((flg, "".join(sorted(test_menu))))
        # 백트래킹, 다시 채워줌
        for m in menu:
            menu_set.add(m)
    
    # 2개 이상 나왔던 메뉴들 중 가장 많이 팔렸던 메뉴 선택하기 위한 최대값 찾음
    maxi = max(candi, key=lambda x:x[0])[0] if len(candi) > 0 else -1
    ret1 = set()
    ret2 = set()
    # ret1 은 정답에 더해줄 리스트, ret2 는 다음 탐색을 위한 후보들
    for val, menu in candi:
        if maxi != -1 and val == maxi:
            ret1.add(menu)
        ret2.add(menu)
    return list(ret1), list(ret2)
            
def solution(orders, course):
    answer = []
    
    # menu_set 은 뽑을 수 있는 메뉴의 집합
    menu_set = set()
    for order in orders:
        menu_set = menu_set.union(set(order))
    
    bef = 1
    candidates = sorted(menu_set)
    # course로 들어온 단품메뉴의 수들에 대해 검사할때 전부 검사하는 것이 아니라
    # 직전 탐색에서 2개 이상 가능하다고 나왔던 메뉴들에 대해서만 검사
    for set_length in course:
        ans, candidates = course_traversal(bef, set_length, candidates, menu_set, orders)
        bef = set_length
        answer += ans
    
    return sorted(answer)
