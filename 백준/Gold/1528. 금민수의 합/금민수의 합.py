from collections import deque

def find_goldminsu(num):
    if num > N:
        return
    if num != 0:
        goldminsu.append(num)
    for digit in (4, 7):
        find_goldminsu(num * 10 + digit)

N = int(input())

goldminsu = []
find_goldminsu(0)
goldminsu.sort()

dp = [-1] * (N + 1)
prev = [-1] * (N + 1)
used = [-1] * (N + 1)

dp[0] = 0
q = deque([0])

while q:
    cur = q.popleft()
    for gold in goldminsu:
        nxt = cur + gold
        if nxt > N:
            continue
        if dp[nxt] == -1:
            dp[nxt] = dp[cur] + 1
            prev[nxt] = cur
            used[nxt] = gold
            q.append(nxt)

if dp[N] == -1:
    print(-1)
else:
    path = []
    cur = N
    while cur != 0:
        path.append(used[cur])
        cur = prev[cur]
    print(*reversed(path))
