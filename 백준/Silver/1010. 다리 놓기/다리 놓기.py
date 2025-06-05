N = int(input())
for _ in range(N):
    K, M = map(int, input().split())
    K, M = max(K, M), min(K, M)
    M = min(K-M, M)
    
    ans = 1
    for i in range(0,M):
        ans *= K-i
    for i in range(1,M+1):
        ans = ans // i
    print(ans)