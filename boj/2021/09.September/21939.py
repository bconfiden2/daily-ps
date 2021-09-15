import sys
import heapq
input = sys.stdin.readline

N = int(input())
# 문제를 어려운 순으로 관리할 hardq, 쉬운 순으로 관리할 easyq
hardq = []
easyq = []
# 문제번호:난이도 의 형태를 갖는 딕셔너리를 통해 내가 이 문제를 풀었는지 안풀었는지 확인
prbm = {}
# prbm과 두개의 큐를 처음 입력값으로 초기화
for _ in range(N):
    num, deg = map(int, input().split())
    prbm[num] = deg
    heapq.heappush(hardq, (-deg, -num))
    heapq.heappush(easyq, (deg, num))
M = int(input())
# 명령어가 들어올 때
for _ in range(M):
    line = input().split()
    # 문제를 추가할 경우 동일하게 prbm 과 두개의 큐에 모두 반영
    if line[0] == 'add':
        num, deg = int(line[1]), int(line[2])
        prbm[num] = deg
        heapq.heappush(hardq, (-deg, -num))
        heapq.heappush(easyq, (deg, num))
    
    elif line[0] == 'recommend':
        # 어려운 문제를 추천해줄 경우
        if line[1] == '1':
            # 앞서서 solve 됐던 문제들을 큐에서 다 빼주고(같은 문제가 다른 난이도로 들어올 경우도 제외)
            while prbm[-hardq[0][1]] < 0 or prbm[-hardq[0][1]] != -hardq[0][0]:
                heapq.heappop(hardq)
            # solve 하지 않은 문제들 중 가장 우선순위를 갖는 문제 추천
            print(-hardq[0][1])
        else:
            while prbm[easyq[0][1]] < 0 or prbm[easyq[0][1]] != easyq[0][0]:
                heapq.heappop(easyq)
            print(easyq[0][1])
    # solved 의 경우는, prbm 의 값을 음수로 바꿔줌으로써 solve 처리
    else:
        prbm[int(line[1])] *= -1