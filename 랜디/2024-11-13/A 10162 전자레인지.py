T = int(input())
A,B,C = 0,0,0

A += T//300
T -= A*300

B += T//60
T -= B*60

C += T//10
T -= C*10

if T==0 : print(A, B, C)
else : print(-1)
