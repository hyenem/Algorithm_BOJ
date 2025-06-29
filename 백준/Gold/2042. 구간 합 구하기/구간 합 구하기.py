# 1이 2에 속하는가?
def rangecompare(s2, e2, s1, e1):
    if e1<s2 or e2<s1: return 0
    if s2<=s1 and e1<=e2: return 2
    return 1

def fillLR(node):
    if left[node]==right[node]:return
    left[node*2]=left[node]
    right[node*2] = (left[node]+right[node])//2
    left[node*2+1] = (left[node]+right[node])//2+1
    right[node*2+1] = right[node]
    fillLR(node*2)
    fillLR(node*2+1)


def change(nth, node, dist):
    tree[node] += dist
    if left[node]==right[node]: return
    if nth<=right[node*2]:
        change(nth, node*2, dist)
    else:
        change(nth, node*2+1, dist)

def find(node, start, end):
    rc = rangecompare(start, end, left[node], right[node])
    if rc==0: res = 0
    elif rc==2: res = tree[node]
    else: res = find(node*2, start, end) + find(node*2+1, start, end)
    # print(node, res)
    return res

def printtree():
    i = 1
    while i<2*N:
        for k in range(i, i*2):
            print(tree[k], end=' ')
        i*=2
        print()

N, M, K = map(int, input().split())
tree = [0]*(4*N)
left = [0]*(4*N)
right = [0]*(4*N)
lst = [0]*(N+1)

left[1]=1
right[1]=N
fillLR(1)

for i in range(1, N+1):
    num = int(input())
    lst[i]=num
    change(i, 1, num)
# print(tree)

for _ in range(M+K):
    a, b, c = map(int, input().split())
    if a==1:
        change(b, 1, c-lst[b])
        lst[b] = c
    else:
        print(find(1, b, c))
    # printtree()
