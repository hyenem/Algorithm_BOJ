import heapq

T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    arr = [0]+list(map(int, input().split()))

    adj = [[] for _ in range(N+1)]
    indegree = [0]*(N+1)
    for _ in range(K):
        v1, v2 = map(int, input().split())
        adj[v1].append(v2)
        indegree[v2]+=1

    q = []
    for i in range(1, N+1):
        if indegree[i]==0:
            heapq.heappush(q, (arr[i], i))

    W = int(input())
    while q:
        time, build = heapq.heappop(q)
        if build == W:
            print(time)
            break
        for ele in adj[build]:
            indegree[ele]-=1
            if indegree[ele]==0:
                heapq.heappush(q, (time+arr[ele], ele))

