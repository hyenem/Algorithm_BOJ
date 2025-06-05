def compute(p1, p2):
    if idx[p1]>maxidx[p1] or idx[p2]>maxidx[p2]:
        return 0

    r1, r2 = rcp[p1][idx[p1]], rcp[p2][idx[p2]]
    if winlose[r1][r2]==2:
        win[p1]+=1
        if win[p1]>=K:
            if p1==0: return 1
            else: return 0

        if p2==1: np1, np2 = 0, 2
        else : np1, np2 = 0, 1
    else:
        win[p2]+=1
        if win[p2]>=K:
            return 0
        if p1==0: np1, np2 = 1, 2
        else: np1, np2 = 0, 2

    idx[p1] += 1
    idx[p2] += 1

    return compute(np1, np2)
    

def btk():
    global ans, win, idx
    if ans==1: return
        
    if len(rcp[0])==N:
        win = [0, 0, 0]
        idx = [0, 0, 0]
        ans = compute(0, 1)
        return
        
    for i in range(N):
        if visited[i]: continue
        visited[i]=1
        rcp[0].append(i)
        btk()
        rcp[0].pop()
        visited[i]=0

N, K = map(int, input().split())
winlose = [list(map(int, input().split())) for _ in range(N)]

rcp = [[], list(map(lambda x:int(x)-1, input().split())), list(map(lambda x:int(x)-1, input().split()))]

idx = [0, 0, 0]
maxidx = [N-1, 19, 19]
visited = [0]*N
win = [0, 0, 0]

ans = 0
btk()
print(ans)