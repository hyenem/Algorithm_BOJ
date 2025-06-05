c = int(input())
tc = [int(input()) for _ in range(c)]
M = max(tc)

dic = {(0, 0):1}
dxdy = ((-2, 0), (-1, -1), (1, -1), (2, 0), (1, 1), (-1, 1))
x, y = 0, 0

cnt = [0]*6
cnt[1]=1
ans = [0, 1]

repeat = 1;
while len(ans)<=M:
    for d in range(6):
        for r in range(repeat):
            if d==0 and r==0:
                x, y = x-1, y+1
            else:
                x, y = x+dxdy[d][0], y+dxdy[d][1]
        
            visited = [0]*6
            for dx, dy in dxdy:
                nx, ny = x+dx, y+dy
                if (nx, ny) in dic:
                    visited[dic[(nx, ny)]]=1
        
            tile = 0
            mincnt = 10001
            for ti in range(1, 6):
                if visited[ti]: continue
                if cnt[ti]<mincnt:
                    mincnt=cnt[ti]
                    tile = ti
        
            cnt[tile] += 1
            ans.append(tile)
            dic[(x, y)]=tile

            if len(ans)>M: break
        if len(ans)>M: break
    repeat+=1
    
                
for t in tc:
    print(ans[t])