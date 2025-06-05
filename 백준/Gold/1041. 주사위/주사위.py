two = ((1,2,3,4), (2,3,5), (4,5), (4,5), (5,))
three = (((1,3), (3,4), (2,4), (1,2)), ((3,5), (5,2)), ((4,5),), ((4, 5),))

ans = 0
N = int(input())
arr = list(map(int,input().split()))

if N==1:
    print(sum(arr)-max(arr))
else:

    ans += ((N-1)*(N-2)*4+(N-2)**2)*min(arr)

    twomin = 300
    for i in range(5):
        for j in two[i]:
            twomin = min(twomin, arr[i]+arr[j])
    ans += twomin*(8*N-12)

    threemin= 300
    for i in range(4):
        for j, k in three[i]:
            threemin = min(threemin, arr[i]+arr[j]+arr[k])
    ans += threemin*4

    print(ans)