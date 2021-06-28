N = int(input())

img = [list(map(int, input().split())) for i in range(N)]

def filter(img, r, c):      # 4칸 중 두번째 높은 값 반환해주는 함수
    return sorted([img[r][c], img[r][c+1], img[r+1][c], img[r+1][c+1]])[-2]

def pooling(img):           # stride=2 로 풀링하는 함수
    return [[filter(img, r, c) for c in range(0, len(img), 2)] for r in range(0, len(img), 2)]

while len(img) > 1:         # 1 x 1 이 될 때 까지 풀링을 반복
    img = pooling(img)

print(img[0][0])