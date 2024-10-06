#모든 칸에 퀸을 놓는 것이 최적이다.

a,b = map(int, input().split())
ans = (a-1)*b + (b-1)*a + 2*(a-1)*(b-1)
print(ans)
