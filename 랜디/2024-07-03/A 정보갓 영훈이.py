import sys
score = 0
arr = []
N = int(sys.stdin.readline().strip())
for _ in range(N):
    S,A,T,M = map(float, sys.stdin.readline().split())
    score += S*(1+1/A)*(1+M/T)/4
P = int(sys.stdin.readline().strip())
for _ in range(P):
    x = float(sys.stdin.readline().strip())
    arr.append(x)
score = float(format(score,".2f"))
arr.append(score)
arr.sort(reverse=True)

if(arr.index(score)+1 <= len(arr)*(15/100)):
    print('The total score of Younghoon "The God" is %.2f.' %score)
else:
    print('The total score of Younghoon is %.2f.' %score)


# S 각 문제 별 개수
# A 시도 횟수
# T 구동 시간
# M 그 문제의 해답 소스 중 가장 빠른 것의 구동 시간
# 점수 = S*(1+1/A)*(1+M/T)/4
