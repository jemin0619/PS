import sys

while(True):
    n = int(sys.stdin.readline())
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
