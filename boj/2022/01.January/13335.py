from collections import deque
n, w, L = map(int, input().split())
truck = list(map(int, input().split()))
idx, sum, cnt = 1, truck[0], 2
# 맨 처음 트럭은 무조건 올라간 뒤 시작
bridge = deque([(w+1, truck[0])])
while idx < n:
    # 만약 다리에서 가장 앞에 있는 트럭이 도착한 경우
    if bridge[0][0] == cnt:
        sum -= bridge[0][1]
        bridge.popleft()
    # 트럭이 빠진 뒤 새로운 트럭이 올라갈 수 있다면 올림
    if sum + truck[idx] <= L:
        bridge.append((cnt+w, truck[idx]))
        sum += truck[idx]
        idx += 1
    cnt += 1
# 마지막 트럭이 도착할 시간을 출력
print(bridge[-1][0])