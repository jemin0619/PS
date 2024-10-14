# 7 TLE, 2 WA, AC
# 계속 TLE가 나서 코드를 고쳐보니 WA가 나고... 다음 날에 다시 시도했다.
# 문제의 원인은 나눗셈에서 // 를 하지 않으면 double로 결과가 반환되는데, 이 double을 int로 변환해버리는 로직이 문제였다.
# 10**100을 double로 나눗셈 처리를 하니 TLE가 발생했던 것이다.
# 파이썬에 익숙하지 않아서 실수했다. 
# 수식은 모두 직접 유도했는데 재미있었다.

# 수열을 구간별로 나눌 수 있다.
# 1 // 2 4 // 5 7 9 // 10 12 14 16 // ...
# 각 구간의 시작 수는 계차수열임을 알 수 있고, 이의 일반항은 An = n**2 - 2n + 2 이다.
# 각 구간의 시작 인덱스 또한 계차수열임을 알 수 있고, 일반항을 뽑아내면 An = (n**2 - n)/2 + 1 이다.
# 두 수식 모두 n을 구간의 번호로 정의한다. (수열에서 1은 구간 1에 속해있고, 5는 구간 3에 속해있다.)

# N이 포함되는 시작 인덱스를 이분 탐색으로 구한다. 
# 5가 입력되었을 때 st=3, en=4 가 될 것이다.
# 구간 3에 답이 존재한다는 것이므로 구간 3의 시작 수를 수식 1을 통해 구한다.
# 첫 번째 구간을 제외하면 각 구간은 공차가 2인 등차수열의 형식을 띄므로 
# 구간의 시작 수 + (구할 수의 인덱스 - 시작 구간의 인덱스)*2 를 구해주면 답이 된다.

import sys
N = int(sys.stdin.readline())
st, en = 0, (10**100)+1
while st+1<en:
    mid = (st+en)//2
    if ((mid-1)*mid)//2 + 1<=N : st=mid
    else : en=mid
ans = st*st-2*st+2 + 2*(N-(((st-1)*st)//2 + 1))
print(ans)
