### 일반 출력
```py
#C++ 마냥 기호 앞엔 \ 사용가능

print("hello World")
print(""hi"") #ERROR
print("\"hi\"")
```
- python만의 간편한 출력 기능이 있지만 형식적으로 사용하기

### 기초 입/출력
```py
#문자 입출력
n = input()
print(n)

#숫자 형 변환 입/출력 (int float)
n = int(input())
print(n)

#여러 줄의 입력을 받을 땐 input을 각각 써야 한다.
n = int(input())
m = int(input())
print(n)
print(m)

#한 줄로 나오는 입력을 받을 땐 다음과 같이 해야 한다.
import sys
n, m = map(int, sys.stdin.readline().split())
print(n)
print(m)

#한 줄에 n m을 출력하고 싶다면 다음과 같이 할 수 있다.
print(n,m) #result: n m
print(n+m) #result: nm

#영문자 10진수 변환 (글자 사이 거리 출력)
import sys
n,m = sys.stdin.readline().split()
val = int(ord(m)-ord(n))
print(val)

#다음 문자 출력하기
n = (input())
print(chr(ord(n)+1))
```
- 입력이 어떻게 들어오는지에 따라 입력 방식이 두 가지로 나뉜다
- 기본적으론 string type으로 입력이 받아지는 듯 하다
- 문자열 s를 s[a:b]를 사용해 a ~ b-1번째 문자까지 자를 수 있다. (0-indexed)
- ord() -> 문자를 정수로 변경
- chr() -> 정수를 문자로 변경

### [Codeup 6036 단어 여러 번 출력하기](https://codeup.kr/problem.php?id=6036)
```py
import sys
n,m = sys.stdin.readline().split()
m = int(m)
for k in range(m):
    print(n,end='')
```


### [Codeup 6040](https://codeup.kr/problem.php?id=6040)
```py
import sys
n,m = map(int, sys.stdin.readline().split()) #10 3
print(n//m)    # 3
print(n%m)     # 1
print(n/m)     # 3.3333333333333335
```
- // 나누기 연산 (강제 floor)
- % 모듈러 연산
- / 나누기 연산 (floor X)

### [Codeup 6041](https://codeup.kr/problem.php?id=6042)
```py
n = float(input())
print(format(n,".2f"))
```

### [Codeup 6081](https://codeup.kr/problem.php?id=6081)
```py
x = int(input(),16)
for i in range(1,16):
    print('%X'%x, '*%X'%i, '=%X'%(x*i),sep='')
```
- int형 진수변환
- 16진수 출력하기
- 여러 요소 붙여서 출력하기 (sep)

### [Codeup 6082](https://codeup.kr/problem.php?id=6082)
```py
x = int(input())
for i in range(1,x+1):
    flag = False
    for S in str(i):
        if(S=='3' or S=='6' or S=='9'): flag=True;  break
    if(flag): print('X',end=' ')
    else: print(i,end=' ')
```

### [Codeup 6083](https://codeup.kr/problem.php?id=6083)
```py
import sys
R,G,B = map(int, sys.stdin.readline().split())
for r in range(R):
    for g in range(G):
        for b in range(B):
            print(r, g, b)
print(R*G*B)
```
- 빠른 입력은 사용해도 빠른 출력은 굳이 쓰지 않는 것 같음

### [Codeup 6091](https://codeup.kr/problem.php?id=6091)
```py
import sys
import math

def lcm(a,b):
    return a*b//math.gcd(a,b)

a,b,c = map(int, sys.stdin.readline().split())
print(lcm(lcm(a,b),c))
```
- import math
- GCD와 LCM

### [Codeup 6092](https://codeup.kr/problem.php?id=6092)
```py
import sys
d = [0]*24
n = int(input())
l = list(map(int,sys.stdin.readline().split()))
for i in l:
    d[i]+=1
for i in range(1,24):
    print(d[i],end=' ')
```
- 1차원 배열 크기 선언 즉시 할당시키기

### [Codeup 6093](https://codeup.kr/problem.php?id=6093)
```py
import sys
n = int(input())
a = list(map(int,sys.stdin.readline().split()))

a.reverse()

for i in a:
    print(i,end=' ')
```
- list에 존재하는 reverse 매서드
- map 객체를 list로 변경

### [Codeup 6094](https://codeup.kr/problem.php?id=6094)
```py
import sys
n = int(input())
a = list(map(int,sys.stdin.readline().split()))
print(min(a))
```
- min 함수의 인자로 list를 넣을 수도 있다

### [Codeup 6095](https://codeup.kr/problem.php?id=6095)
```py

#문제에서 x y 입력이 생각했던 것과 반대여서 한 번 틀렸음


d = [[0]*20 for _ in range(20)]
n = int(input())
for i in range(n):
    y,x = map(int,sys.stdin.readline().split())
    d[y][x] = 1

for i in range(1,20):
    for j in range(1,20):
        print(d[i][j],end=' ')
    print()
```
- 2차원 list에 크기 할당하기
