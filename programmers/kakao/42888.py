def solution(record):
    ans = []
    kv = dict()
    # 입장/이름변경시에는 {id:이름} 딕셔너리 업데이트
    # 입장은 (id,0), 퇴장은 (id,1)로 표시
    for r in record:
        cmd = r.split()
        if cmd[0] == 'Enter':
            ans.append((cmd[1],0))
            kv[cmd[1]] = cmd[2]
        elif cmd[0] == 'Leave':
            ans.append((cmd[1],1))
        else:
            kv[cmd[1]] = cmd[2]
    # 입/퇴장 기록을 최종 id에 맞춰서 출력
    tmp = ["들어왔","나갔"]
    return [kv[v[0]]+"님이 "+tmp[v[1]]+"습니다." for v in ans]
