import sys
import heapq

V, E, P = map(int, input().split())
graph = [[] for _ in range(V+1)]
# 그래프 양방향으로 연결
for line in sys.stdin:
    a, b, c = map(int, line.strip().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

# 다익스트라로 시작점과 끝점까지의 최소 거리 반환
def dijkstra(start, end):
    # answer[i] 는 start 부터 i 까지의 최소 거리
    answer = [10e8 for i in range(V+1)]
    pq = []
    # 시작점 pq 에 담고 출발
    heapq.heappush(pq, (0, start))
    answer[start] = 0

    while len(pq) > 0:
        dist, node = pq[0]
        heapq.heappop(pq)
        # pq 에 푸시됐지만 중간에 다른 노드에서 최소비용이 또 갱신됐을 경우 대비
        if dist > answer[node]:
            continue
        # 목적지까지의 최소거리를 찾게 되면 종료
        if node == V:
            break
        # 현재 위치에 연결된 모든 노드들 중에
        for nextnode, nextdist in graph[node]:
            # 최소 거리를 갱신할 수 있는 노드들에만 대해서
            if dist+nextdist < answer[nextnode]:
                # 비용 갱신 후 pq 에 추가
                answer[nextnode] = dist+nextdist
                heapq.heappush(pq, (dist+nextdist, nextnode))
    return answer[end]

# 민준이가 마산으로 가는 최소비용이, 건우까지 가는 최소비용 + 건우에서 마산으로 가는 최소비용 과 같다면 구하러 감
print("SAVE HIM" if dijkstra(1, V) == dijkstra(1, P) + dijkstra(P, V) else "GOOD BYE")