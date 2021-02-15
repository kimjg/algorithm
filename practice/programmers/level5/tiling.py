def tiling(n):
    answer = 0

    dp = [0]*(n+1)

    def solve(n):

        num = 0
        if(n < 0):
            return 0
        if(n == 0):
            return 1
        if(dp[n] > 0):
            return dp[n]
        num = solve(n - 1) + solve(n - 2)
        dp[n] = num % 100000
        return dp[n]

    answer = solve(n)
    return answer


# 아래는 테스트로 출력해 보기 위한 코드입니다.
print(tiling(2))
