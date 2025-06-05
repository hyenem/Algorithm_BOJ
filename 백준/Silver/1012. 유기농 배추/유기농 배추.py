T = int(input())

dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)

for _ in range(T):
    M, N, K = map(int, input().split())
    arr = [[False]*M for _ in range(N)]
    points = []
    ans = 0
    for _ in range(K):
        x, y = map(int, input().split())
        arr[y][x] = True
        points.append((x, y))
    for point in points:
        if arr[point[1]][point[0]]:
            ans += 1
            arr[point[1]][point[0]]= False
            q = [(point[0], point[1])]
            while len(q)!=0:
                item = q.pop(0)
                for k in range(4):
                    nx = item[0]+dx[k]
                    ny = item[1]+dy[k]
                    if 0<=nx<M and 0<=ny<N and arr[ny][nx]:
                        q.append((nx, ny))
                        arr[ny][nx]=False
    print(ans)
                
                