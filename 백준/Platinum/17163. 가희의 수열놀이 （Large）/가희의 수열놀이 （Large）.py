import sys

input = sys.stdin.readline
def fill(node, idx, num, left, right):
    if left==right:
        tree[node] = idx
        return
    mid = (left+right)//2
    if num<=mid: fill(node*2, idx, num, left, mid)
    else : fill(node*2+1, idx, num, mid+1, right)
    tree[node] = min(tree[node*2], tree[node*2+1])


Q, mod = map(int, input().split())
if Q<mod:
    for _ in range(Q):
        query = input()
        if query[0]=='3':
            print(-1)

else:
    tree = [-1]*(4*mod)
    history = [[] for _ in range(mod)]
    arr = []
    idx = 0
    for _ in range(Q):
        query = input()
        if query[0] == '1':
            idx += 1
            num = int(query[2:])%mod
            arr.append(num)
            history[num].append(idx)
            fill(1, idx, num, 0, mod-1)
        elif query[0] == '2':
            if arr:
                num = arr.pop()
                history[num].pop()
                if history[num]: bidx = history[num][-1]
                else : bidx = -1
                idx -= 1
                fill(1, bidx, num, 0, mod-1)
        else:
            print(-1 if tree[1]==-1 else idx-tree[1]+1)