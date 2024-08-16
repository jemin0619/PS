import sys
N = int(input())
A = list(map(int,sys.stdin.readline().split()))
Player = A[0]
A = A[1:N]
A.sort()
for i in range(len(A)):
    if(Player > A[i]): Player += A[i]
    else:
        print('No')
        exit()
print('Yes')
