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
