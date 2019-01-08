import math

def setAlign(n, k):
    answer = []

    lines = []
    for i in range(1, n+1):
        lines.append(i)

    multiple = [0]*n
    temp = 1
    for i in range(1, n + 1):
        temp *= i
        multiple[i - 1] = temp

    multiple = sorted(multiple, reverse=True)

    extra = k
    for i in range(1,n+1):

        if i < n:
            index = math.ceil(extra/multiple[i]) - 1
            answer.append(lines.pop(index))
            extra %= multiple[i]
        else :

            answer.append(lines.pop(0))
    return answer


# 아래는 테스트로 출력해 보기 위한 코드입니다.
print(setAlign(3, 5))
