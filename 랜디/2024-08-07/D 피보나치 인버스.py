#피보나치 수열의 뒷 10자리만 따서 키로 저장하는 풀이도 있고, 
#lower_bound로 인덱스를 찾는 방법도 있었는데, 그냥 깡으로 풀었다.
#파이썬이 이렇게 무식하게 풀기 좋은 것 같다.

import sys

T = int(sys.stdin.readline())

dp = [0, 1]
memo = {}

memo[0] = 0
memo[1] = 1

for i in range(2, 100001):
    dp.append(dp[i-1]+dp[i-2])
    memo[dp[i]] = i

for _ in range(T):
    N = int(sys.stdin.readline())
    print(memo[N])
