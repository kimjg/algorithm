import math

def expressions(num):
    answer = 1

    sum = [0]
    for i in range(1, num+1):
        sum.append(sum[i-1] + i)

    for i in range(num+1):
        pv_left = i
        pv_right = int(num/2) + 1
        while pv_left <= pv_right:
            j = int((pv_left + pv_right) / 2)
            value = sum[j] - sum[i]
            if(value > num):
                pv_right = j - 1
            elif(value < num):
                pv_left = j + 1
            else :
                answer += 1
                break
    return answer


# 아래는 테스트로 출력해 보기 위한 코드입니다.
print(expressions(15));
