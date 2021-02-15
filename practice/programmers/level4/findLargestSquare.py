def findLargestSquare(board):
    answer = 0
    n = len(board)
    m = len(board[0])
    dp = [[0] * m for i in range(n)]
    def solve(x, y):
        if n <= y:
            return 0
        if m <= x:
            return 0
        if dp[y][x] > 0:
            return dp[y][x]

        if board[y][x] == 'O':
            maxSize = min(solve(x + 1, y), solve(x, y + 1), solve(x + 1, y + 1)) + 1
        else:
            return 0

        dp[y][x] = maxSize

        return maxSize

    for y in range(n):
        for x in range(m):
            solve(x, y)

    for y in range(n):
        for x in range(m):
            answer = max(answer, dp[y][x])

    return answer ** 2