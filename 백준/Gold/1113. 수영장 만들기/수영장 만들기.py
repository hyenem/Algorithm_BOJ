'''
* 제출횟수 : 6회
* 실행시간 : 1276ms
* 메모리 : 147100KB

* Review
* while문 끝나는 조건을 boolean flag로 한번에 하려다가
* 한 반복문에서 두 번 돌다가 두번째가 break걸려버리면
* 변화가 있었는데도 break 걸려서 문제가 생김
* 질문 계시판 반례 봐버림,,,
'''

from collections import deque

def check_min(x, y):
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if arr[nx][ny] < arr[i][j]:
            return False
    return True

N, M = map(int, input().split())
arr =[[0]*(M+2)] + [[0]+list(map(int, input()))+[0] for _ in range(N)] +[[0]*(M+2)]
ans = 0

dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)

change_cnt = 1
total_visited = [[False]*(M+1) for _ in range(N+2)]
while change_cnt:
    change_cnt = 0
    for i in range(1, N+1):
        for j in range(1, M+1):
            if total_visited[i][j]: continue
            flag = False
            if check_min(i, j):
                ischecked = True
                height = 9
                q = deque()
                visited = [0]*(N+2)
                visited[i]|=(1<<j)
                q.append((i, j))
                stack = []
                height=9
                flag = True
                while q:
                    x, y = q.popleft()
                    stack.append((x, y))
                    for k in range(4):
                        nx = x+dx[k]
                        ny = y+dy[k]

                        if arr[nx][ny]>arr[x][y]:
                            height = min(height, arr[nx][ny]-arr[x][y])
                        if visited[nx]&(1<<ny)==0 and arr[x][y]==arr[nx][ny]:
                            if check_min(nx, ny):
                                visited[nx]|=(1<<ny)
                                q.append((nx, ny))
                            else :
                                total_visited[nx][ny]=True
                                ischecked = False
                                break
                    if not ischecked : break
                if ischecked:
                    change_cnt+=1
                    ans += len(stack)*height
                    while stack:
                        x, y = stack.pop()
                        arr[x][y] += height
            else :
                total_visited[i][j]=True
print(ans)
