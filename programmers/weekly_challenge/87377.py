def solution(line):
    points = set()
    maxX, maxY, minX, minY = -10e10, -10e10, 10e10, 10e10
    # 입력받은 모든 선분에 대해서
    for i in range(len(line)):
        for j in range(i+1, len(line)):
            A, B, E = line[i]
            C, D, F = line[j]
            tmp = A * D - B * C
            # 교차하는 점이 있고, 해당 점의 (x,y) 좌표가 둘 다 정수일 경우에만
            if tmp != 0 and (B*F-E*D)%tmp == 0 and (E*C-A*F)%tmp == 0:
                X, Y = (B*F-E*D)//tmp, (E*C-A*F)//tmp
                # 점들에 추가해주고, 각 최대최소값들을 갱신
                maxX, maxY, minX, minY = max(maxX, X), max(maxY, Y), min(minX, X), min(minY, Y)
                points.add((X, Y))
    # 정답 좌표계를 각 좌표들 중 최대값들로만 압축시킨 뒤
    answer = [["." for c in range(maxX-minX+1)] for r in range(maxY-minY+1)]
    # 점들을 해당 좌표계에 찍어줌
    for x, y in points:
        answer[maxY-y][x-minX] = "*"
    return ["".join(row) for row in answer]