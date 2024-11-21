#중간고사 성적 - 기말고사 성적이 답

N = int(input())
V = list(map(int, input().split()))
score = [0]*(N+3)
for i in range(N):
    score[V[i]-1] = i
for i in range(N):
    print(i-score[i])
