input()
arr = list(map(int, input().split()))
ans, cnt = 0, 0
for i in range(len(arr)):
    if(arr[i]==0): cnt=0
    else: cnt+=1
    ans = max(ans, cnt)
print(ans)
