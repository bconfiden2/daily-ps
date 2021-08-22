def solution(board, moves):
    answer = 0
    N = len(board)
    # 각 레일별로, 뽑힐 경우 몇번째 행을 봐야하는지
    indices = [sum(1 if board[r][c]==0 else 0 for r in range(N)) for c in range(N)]
    
    basket = [0]
    for rail in moves:
        # 레일 인덱스 0 ~ N-1 로 맞추기
        rail -= 1
        # 해당 레일에 인형이 남아 있을 때만
        if indices[rail] < N:
            # 인형을 뽑아서 바구니에 넣어줌
            basket.append(board[indices[rail]][rail])
            indices[rail] += 1
            # 만약 바구니의 2개가 같은 인형이라면 터트림
            if basket[-1] == basket[-2]:
                answer += 2
                basket.pop()
                basket.pop()
            
    return answer