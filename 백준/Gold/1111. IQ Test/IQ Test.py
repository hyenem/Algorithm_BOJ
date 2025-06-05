def solution():
    if len(arr)==2 and arr[0]==arr[1]:
        print(arr[0])
        return

    if len(arr)<3:
        print('A')
        return

    if arr[0]==arr[1]:
        if len(set(arr))==1:
            print(arr[0])
        else :
            print('B')
        return


    a = (arr[2]-arr[1])//(arr[1]-arr[0])
    b = arr[1]-arr[0]*a
    for i in range(1, N):
        if arr[i] != arr[i-1]*a +b:
            print('B')
            return
    print(a*arr[N-1]+b)

N = int(input())
arr = list(map(int, input().split()))
solution()