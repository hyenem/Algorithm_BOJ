N = int(input())
adj = [set() for _ in range(N+1)]
for _ in range(N-1):
    i, j = map(int, input().split())
    adj[i].add(j)
    adj[j].add(i)

check = list(map(int, input().split()))
stack = [1]

for idx in range(1, N):
    
    while stack:
        if check[idx] in adj[stack[-1]]:
            stack.append(check[idx])
            break
        else:
            stack.pop()

if len(stack)==0:
    print(0)
else:
    print(1)