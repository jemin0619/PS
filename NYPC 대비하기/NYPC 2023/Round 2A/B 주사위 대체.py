#Dm 주사위를 Dn 주사위처럼 사용할 수 있는지 묻는 문제이다.
#Dm 주사위를 k번 굴리면 총 m^k개의 경우의 수가 만들어진다.
#이 m^k개의 경우의 수를 모두 같은 갯수만큼 묶어서 n개의 묶음을 만들어 낼 수 있다면 Dm 주사위를 Dn 주사위처럼 쓸 수 있다.
#그 이유는 당연하지만 n개의 수가 나올 확률이 같아졌기 때문이다. (전부 다 (M^k/n) / (M^k)의 확률이 됨)
#(M^k/n) / (M^k) = 1/n (이는 항등식이다.)
#파이썬이라도 모듈러 연산으로 수를 줄이지 않으면 터지는 것 같다.

import sys

T = int(sys.stdin.readline())
for _ in range(T):
    M, N = map(int, sys.stdin.readline().split())
    flag = False
    for k in range(65):
        M = M*M
        M = M%N
        if M%N==0:
            flag = True
            break
    if flag : print("YES")
    else : print("NO")
