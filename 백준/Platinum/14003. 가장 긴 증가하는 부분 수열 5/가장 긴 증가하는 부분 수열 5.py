def binarysearch(x, i):
    left = 0
    right = len(increase)-1
    while left<=right:
        mid = (left+right)//2
        if increase[mid][0]==x:
            return
        elif increase[mid][0]<x:
            left = mid+1
        else:
            right = mid-1
    if left==len(increase):
        parent[i]=increase[-1][1]
        increase.append([x, i])
    else :
        if left==0:
            parent[i]=-1
        else:
            parent[i]=increase[left-1][1]
        increase[left]=([x,i])

N = int(input())
arr = list(map(int, input().split()))
increase = [[arr[0], 0]]
parent = [-1]*(N)
for i in range(1, N):
    binarysearch(arr[i], i)

print(len(increase))
ans = [increase[-1][0]]
idx = increase[-1][1]
while parent[idx]!=-1:
    idx = parent[idx]
    ans.append(arr[idx])
print(*reversed(ans))