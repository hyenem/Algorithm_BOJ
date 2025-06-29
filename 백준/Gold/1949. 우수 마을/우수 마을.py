import sys
sys.setrecursionlimit(10000)

def calmax(now):
    DP[now][0] = population[now]
    DP[now][1] = 0
    DP[now][2] = 0

    allbad = 0
    leaf = 1
    mindist = -1
    for next in adj[now]:
        if DP[next][0]!=-1: continue

        leaf = 0
        calmax(next)

        DP[now][0] += DP[next][1]
        DP[now][1] += max(DP[next][0], DP[next][2])
        if mindist==-1:
            mindist = abs(DP[next][0]-DP[next][2])
        else :
            mindist = min(abs(DP[next][0]-DP[next][2]), mindist)

    DP[now][2] = DP[now][1]
    if not leaf and allbad: DP[now][2]-=mindist


N = int(input())
population = list(map(int, input().split()))
adj = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(lambda x: int(x)-1, input().split())
    adj[a].append(b)
    adj[b].append(a)

# good, bad, bad인데 자식 중 하나는 good
DP = [[-1, -1, -1] for _ in range(N)]
calmax(0)
print(max(DP[0][0], DP[0][2]))