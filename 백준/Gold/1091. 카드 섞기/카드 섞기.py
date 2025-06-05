N = int(input())
P = list(map(int, input().split()))
origin = P[:]
S = list(map(int, input().split()))

ans = -1
flag = True
while flag:
    if ans != -1 and P==origin: break

    ans +=1
    for j in range(N):
        if P[j]!=j%3:
            break
    else :
        flag = False
        break

    tmp = P[:]
    for j in range(N):
        P[S[j]]=tmp[j]

if flag:
    ans=-1
print(ans)