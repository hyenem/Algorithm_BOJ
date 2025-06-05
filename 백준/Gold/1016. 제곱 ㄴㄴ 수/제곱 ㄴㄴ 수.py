import math

m, M = map(int,input().split())
maxroot = int(math.sqrt(M))
visited = [True]*(maxroot+1)
prime = []
for i in range(2, maxroot+1):
    if visited[i]:
        prime.append(i)
        for j in range(2, maxroot//i+1):
            visited[j*i]=False

s = set()
for p in prime:
    start = max(0,m-1)//(p**2) +1
    end = M//(p**2)
    for i in range(start, end+1):
        s.add((p**2)*i)
ans = M-m+1-len(s)
print(ans)