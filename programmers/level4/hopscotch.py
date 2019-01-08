def hopscotch(board, size):
    result = 0
    # 땅따먹기 게임으로 얻을 수 있는 최대 점수는?

    dp = [[0 for col in range(4)] for row in range(size)]
    dp[size - 1] = board[size - 1]

    def solve(i, j):
        num = 0
        if(dp[j][i] > 0):
            return dp[j][i]

        if (i != 0):
            num = max(solve(0, j + 1), num)
        if (i != 1):
            num = max(solve(1, j + 1), num)
        if (i != 2):
            num = max(solve(2, j + 1), num)
        if (i != 3):
            num = max(solve(3, j + 1), num)

        num += board[j][i]
        dp[j][i] = num
        return num


    result = max(solve(0, 0), result)
    result = max(solve(1, 0), result)
    result = max(solve(2, 0), result)
    result = max(solve(3, 0), result)
    print(dp)
    return result


#아래는 테스트로 출력해 보기 위한 코드입니다.
board =  [[ 1, 2, 3, 5 ], [ 5, 6, 7, 8 ], [4, 3, 2, 1]]
print(hopscotch(board, 3))