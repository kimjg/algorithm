

def change(total, coin):
    answer = 0;

    dp = [[0] * (total + 1) for i in range(len(coin))]

    for i in range(len(coin)):
        dp[i][0] = 1

    for n in range(1, total + 1):
        for i in range(len(coin)):
            for j in range(i, len(coin)):
                if n - coin[j] > -1:
                    dp[i][n] += dp[j][n - coin[j]]

    for i in range(len(coin)):
        if n - coin[i] > -1:
            answer += dp[i][n - coin[i]]

    return answer;


# 아래는 테스트로 출력해 보기 위한 코드입니다.
print(change(5, [1, 2, 5]))
