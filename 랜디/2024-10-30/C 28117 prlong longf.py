#long이 여러 개 붙어있을 때의 출력값이 피보나치 수의 규칙과 같음을 알 수 있다.
#피보나치 수 말고 탑다운 dp로 멋지게 구현할 수도 있을 것 같지만 일단 풀기 위해 이 방법을 택했다
#처음에 아이디어를 잘못 떠올려 2% WA를 받았다

N = int(input())
S = input().replace('long', '*')
dp = [0]*83
dp[0]=1
dp[1]=1
dp[2]=2
for i in range(3, 81):
    dp[i] = dp[i-1]+dp[i-2]
cnt = 0
ans = 1
for i in range(len(S)):
    if S[i]=='*':
        cnt += 1
    else: 
        ans *= dp[cnt]
        cnt = 0
ans *= dp[cnt]
print(ans)
