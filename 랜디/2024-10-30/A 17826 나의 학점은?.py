arr = list(map(int, input().split()))
score = int(input())
idx = -1
for i in range(len(arr)):
    if arr[i]==score :
        idx = i+1
        break
if idx<=5 : print('A+')
elif idx<=15 : print('A0')
elif idx<=30 : print('B+')
elif idx<=35 : print('B0')
elif idx<=45 : print('C+')
elif idx<=48 : print('C0')
else : print('F')


#A+: 1~5등
#A0: 6~15등
#B+: 16~30등
#B0: 31~35등
#C+: 36~45등
#C0: 46~48등
#F: 49~50등
