#python 배울 겸 pypy3로 풀었다.
#Q[0]을 먼저 입력받는게 불가능하기에 한 줄을 다 입력받은 뒤 처리를 해야 한다.
#python에서 union find를 구현하는 법을 배웠다.
#return p[u]=find(p[u])가 안되서 아래처럼 식을 조금 변형시켜서 간소화해야 했다.

#처음엔 Small To Large마냥 합치고 set의 size를 출력할까 싶었는데 그것보단 아래 방식으로 O(1)에 처리하는게 나은 방법이었다.

import sys
sys.setrecursionlimit(10**8)

n = int(sys.stdin.readline())
p = [i for i in range(10**6+1)]
ans = [1 for i in range(10**6+1)]

def find(u):
    if(u!=p[u]): p[u]=find(p[u])
    return p[u]

def union(u,v):
    u = find(u); v = find(v)
    if(u==v): return
    p[min(u,v)] = max(u,v)
    ans[max(u,v)]+=ans[min(u,v)]
    ans[min(u,v)]=0

for _ in range(n):
    Q = sys.stdin.readline().split()
    if(Q[0]=='I'): 
        u = int(Q[1]); v = int(Q[2])
        union(u,v)

    if(Q[0]=='Q'): 
        u = int(Q[1])
        u = find(u)
        print(ans[u])
