#수가 커서 python으로 해결했다.
#비트마스킹으로 패턴을 찾을 수 있다.
#웰노운같은데 처음 보면 많이 어려울 것 같다.

import sys

while(True):
    n = int(input())
    if(n==0): break
    n -= 1
    bin = list(format(n, 'b'))
    bin.reverse()
    ans = []
    for i in range(len(bin)):
        if(bin[i]=='0'): continue
        ans.append(3**int(i))
    if(len(ans)==0): print("{ }")
    else:
        result = "{ " + ", ".join(map(str,ans)) + " }"
        print(result)
