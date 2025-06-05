N, M = map(int, input().split())

arr = [[0 for _ in range(M)] for _ in range(N)]
DP = [[0 for _ in range(M)] for _ in range(N)]

for i in range(N):
    tmp = input()
    for j in range(M):
        if (i+j)%2 == 0 and tmp[j]=='W':
            arr[i][j]=1
        elif (i+j)%2 !=0 and tmp[j]=='B':
            arr[i][j]=1

DP[0][0]=arr[0][0]
for j in range(1, M):
    DP[0][j]=DP[0][j-1]+arr[0][j]
for i in range(1, N):
    DP[i][0]=DP[i-1][0]+arr[i][0]
    for j in range(1, M):
        DP[i][j] = arr[i][j]+DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1]

ans = min(DP[7][7], 64-DP[7][7])
for i in range(8, N):
    ans = min(ans, DP[i][7]-DP[i-8][7])
    ans = min(ans, 64- DP[i][7]+DP[i-8][7])
for i in range(8, M):
    ans = min(ans, DP[7][i]-DP[7][i-8])
    ans = min(ans, 64-DP[7][i]+DP[7][i-8])
for i in range(8, N):
    for j in range(8, M):
        ans = min(ans, DP[i][j]-DP[i-8][j]-DP[i][j-8]+DP[i-8][j-8])
        ans = min(ans, 64-DP[i][j]+DP[i-8][j]+DP[i][j-8]-DP[i-8][j-8])
        
print(ans)
