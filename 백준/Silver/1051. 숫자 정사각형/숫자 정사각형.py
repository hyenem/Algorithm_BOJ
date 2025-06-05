N, M = map(int, input().split())
arr = [input() for _ in range(N)]
ans = 1
for i in range(N):
    for j in range(M):
        for w in range(min(i, j)+1):
            if arr[i][j] == arr[i][j-w] and arr[i][j] == arr[i-w][j] and arr[i][j]==arr[i-w][j-w]:
                ans = max(ans, (w+1)*(w+1))
print(ans)