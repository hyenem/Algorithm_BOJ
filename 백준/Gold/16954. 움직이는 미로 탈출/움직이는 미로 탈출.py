from collections import deque

x, y = 7, 0
arr = [list(input()) for _ in range(8)]

dxdy = ((0, 0), (-1, -1), (-1, 0), (-1, 1), (0, 1), (0, -1), (1, -1), (1, 1), (1, 0))
q = deque([(x, y)])

time = 0
while q:
    visited = set()

    while q:
        x, y = q.popleft()
        for dx, dy in dxdy:
            nx, ny = x+dx, y+dy
            if not(0<=nx<8 and 0<=ny<8): continue
            if nx-time>=0 and arr[nx-time][ny]=='#': continue
            if nx-time-1>=0 and arr[nx-time-1][ny]=='#': continue

            visited.add((nx, ny))

    if (0, 7) in visited:
        print(1)
        break
            
    q = deque(visited)
    time += 1
else:
    print(0)
