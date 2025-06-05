T = int(input())
for _ in range(T):
    N = int(input())

    arr1 = [1, 0]
    arr2 = [0, 1]
    for i in range(2, N+1):
        arr1.append(arr1[i - 1] + arr1[i - 2])
        arr2.append(arr2[i - 1] + arr2[i - 2])
    print(arr1[N], arr2[N])