import heapq

N, M = map(int, input().split())
K, *people = map(int, input().split())
if K == 0:
    print(M)
else :
    person = [False]*(N+1)
    parties = [False]*M
    
    for ele in people:
        person[ele]=True
    adj = [[] for _ in range(N+1)]
    for party in range(M):
        num, *data = map(int, input().split())
        for i in range(num):
            if data[i] in people:
                parties[party]=True
            for j in range(i, num):
                adj[data[i]].append((data[j], party))
                adj[data[j]].append((data[i], party))
    q = people
    while q:
        per = heapq.heappop(q)
        for ele in adj[per]:
            if not person[ele[0]] or not parties[ele[1]]:
                parties[ele[1]]=True
                person[ele[0]]=True
                heapq.heappush(q, ele[0])
    print(parties.count(False))