import sys
n = int(input())
maxX, maxY, maxZ, minX, minY, minZ = 0,0,0,0,0,0

for line in sys.stdin:
    a,b,c = map(int, line.strip().split())      # 스트리밍하게 한줄씩 받아서

    x = max(maxX+a, maxY+a)                     # 왼쪽 위치가 가능한 최댓값
    y = max(maxX+b, maxY+b, maxZ+b)             # 중간 위치가 가능한 최댓값
    z = max(maxY+c, maxZ+c)                     # 오른쪽 위치가 가능한 최댓값을 구한 뒤
    maxX, maxY, maxZ = x, y, z                  # 각 위치의 최댓값 업데이트

    x = min(minX+a, minY+a)                     # 최솟값은 똑같이
    y = min(minX+b, minY+b, minZ+b)
    z = min(minY+c, minZ+c)
    minX, minY, minZ = x, y, z

print(max(maxX, maxY, maxZ), min(minX, minY, minZ)) # 가능한 최댓값과 최솟값 출력