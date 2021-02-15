import math

def bestSet(n, s):
    answer = []

    divide = math.floor(s/n)
    if(divide == 0) :
        answer = [-1]
    else :
        extra = s - divide * n
        answer = [divide for _ in range(n)]
        for i in range(extra):
            answer[i] += 1
        answer.reverse()
    return answer


# 아래는 테스트로 출력해 보기 위한 코드입니다.
print(bestSet(3, 13))