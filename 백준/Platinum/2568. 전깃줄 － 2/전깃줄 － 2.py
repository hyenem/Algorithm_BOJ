def binary(x):
    left = 0
    right = len(lenth)-1
    while left<=right:
        mid = (left+right)//2
        if lenth[mid][1]==arr[x][1]:
            return
        elif lenth[mid][1]<arr[x][1]:
            left=mid+1
        else :
            right = mid-1
    if left>=len(lenth):
        if left==0:
            parent[x] = -1
        else : parent[x]=lenth[-1][0]
        lenth.append((x,arr[x][1]))
    else :
        if left==0:
            parent[x] = -1
        else :
            parent[x] = lenth[left-1][0]
        lenth[left]=(x, arr[x][1])

N = int(input())
arr = [tuple(map(int, input().split())) for i in range(N)]
arr.sort()
lenth=[]
parent = [0]*(N+1)

for i in range(N):
    binary(i)

stack=[lenth[-1][0]]
while parent[stack[-1]]!=-1:
    stack.append(parent[stack[-1]])

if N==len(stack):
    print(0)
else:
    print(N-len(stack))
    visited=[False]*(N+1)
    while stack:
        visited[stack.pop()]=True
    ans = []
    for i in range(N):
        if visited[i]:
            continue
        print(arr[i][0])
