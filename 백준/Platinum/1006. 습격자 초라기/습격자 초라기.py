T = int(input())
for _ in range(T):
    N, W = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(2)]

    if N==1:
        if arr[0][0]+arr[1][0]<=W:
            print(1)
        else :
            print(2)
        continue

    elif N==2:
        if arr[0][1]+arr[1][1]<=W and arr[0][0]+arr[1][0]<=W:
            print(2)
        elif arr[0][0]+arr[0][1]<=W and arr[1][0]+arr[1][1]<=W:
            print(2)
        elif arr[0][0]+arr[0][1]<=W or arr[1][0]+arr[1][1]<=W or arr[0][1]+arr[1][1]<=W or arr[0][0]+arr[1][0]<=W:
            print(3)
        else :
            print(4)
        continue
    inf = 2*N

    ans = inf

    # 0과 N-1이 연결이 안되는 경우
    DP = [[inf]*4 for _ in range(N)]
    if arr[0][0]+arr[1][0]<=W: DP[0][3]=1
    else : DP[0][3]=2

    if arr[0][0]+arr[0][1]<=W and arr[1][0]+arr[1][1]<=W:
        DP[1][2]=2

    if arr[0][1]+arr[1][1]<=W:
        DP[1][3]=min(DP[0])+1
    else : DP[1][3]=min(DP[0])+2

    if arr[0][0]+arr[0][1]<=W:
        DP[1][0]=3

    if arr[1][0]+arr[1][1]<=W:
        DP[1][1]=3

    for i in range(2, N):
        if arr[0][i]+arr[1][i]<=W:
            DP[i][3]=min(DP[i-1])+1
        else :
            DP[i][3]=min(DP[i-1])+2

        if arr[0][i]+arr[0][i-1]<=W and arr[1][i]+arr[1][i-1]<=W:
            DP[i][2]=min(DP[i-2])+2

        if arr[0][i]+arr[0][i-1]<=W:
            DP[i][0] = min(DP[i-1][1]+1, min(DP[i-2]) + 3)

        if arr[1][i]+arr[1][i-1]<=W:
            DP[i][1] = min(DP[i-1][0]+1, min(DP[i-2]) + 3)

    ans = min(min(DP[N-1]), ans)

    #0과 N-1이 위아래 다 연결된 경우
    if arr[0][0] + arr[0][-1] <= W and arr[1][0] + arr[1][-1] <= W:
        DP = [[inf] * 4 for _ in range(N)]
        DP[0] = [inf, inf, 2, inf]

        if arr[0][1] + arr[1][1] <= W:
            DP[1][3] = min(DP[0]) + 1
        else:
            DP[1][3] = min(DP[0]) + 2

        for i in range(2, N-1):
            if arr[0][i] + arr[1][i] <= W:
                DP[i][3] = min(DP[i - 1]) + 1
            else:
                DP[i][3] = min(DP[i - 1]) + 2

            if arr[0][i] + arr[0][i - 1] <= W and arr[1][i] + arr[1][i - 1] <= W:
                DP[i][2] = min(DP[i - 2]) + 2

            if arr[0][i] + arr[0][i - 1] <= W:
                DP[i][0] = min(DP[i - 1][1] + 1, min(DP[i - 2]) + 3)

            if arr[1][i] + arr[1][i - 1] <= W:
                DP[i][1] = min(DP[i - 1][0] + 1, min(DP[i - 2]) + 3)

        ans = min(min(DP[N - 2]), ans)

    # 0과 N-1이 위에만 연결된 경우
    if arr[0][0]+arr[0][-1]<=W:
        DP = [[inf] * 4 for _ in range(N)]
        DP[0]=[2, inf, inf, inf]

        if arr[0][1] + arr[1][1] <= W:
            DP[1][3] = min(DP[0]) + 1
        else:
            DP[1][3] = min(DP[0]) + 2

        if arr[1][0] + arr[1][1] <= W:
            DP[1][1] = 3

        for i in range(2, N-1):
            if arr[0][i] + arr[1][i] <= W:
                DP[i][3] = min(DP[i - 1]) + 1
            else:
                DP[i][3] = min(DP[i - 1]) + 2

            if arr[0][i] + arr[0][i - 1] <= W and arr[1][i] + arr[1][i - 1] <= W:
                DP[i][2] = min(DP[i - 2]) + 2

            if arr[0][i] + arr[0][i - 1] <= W:
                DP[i][0] = min(DP[i - 1][1] + 1, min(DP[i - 2]) + 3)

            if arr[1][i] + arr[1][i - 1] <= W:
                DP[i][1] = min(DP[i - 1][0] + 1, min(DP[i - 2]) + 3)

        if arr[1][N-2]+arr[1][N-1]<=W:
            DP[N-1]=[inf, min(DP[N-2][0], min(DP[N-3])+2), inf, min(DP[N-2])+1]
        else : DP[N-1]=[inf, inf, inf, min(DP[N-2])+1]

        ans = min(min(DP[N - 1]), ans)

    # 0과 N-1이 아래만 연결된 경우
    if arr[1][0] + arr[1][-1] <= W:
        DP = [[inf] * 4 for _ in range(N)]
        DP[0] = [inf, 2, inf, inf]

        if arr[0][1] + arr[1][1] <= W:
            DP[1][3] = min(DP[0]) + 1
        else:
            DP[1][3] = min(DP[0]) + 2

        if arr[0][0] + arr[0][1] <= W:
            DP[1][0] = 3

        for i in range(2, N - 1):
            if arr[0][i] + arr[1][i] <= W:
                DP[i][3] = min(DP[i - 1]) + 1
            else:
                DP[i][3] = min(DP[i - 1]) + 2

            if arr[0][i] + arr[0][i - 1] <= W and arr[1][i] + arr[1][i - 1] <= W:
                DP[i][2] = min(DP[i - 2]) + 2

            if arr[0][i] + arr[0][i - 1] <= W:
                DP[i][0] = min(DP[i - 1][1] + 1, min(DP[i - 2]) + 3)

            if arr[1][i] + arr[1][i - 1] <= W:
                DP[i][1] = min(DP[i - 1][0] + 1, min(DP[i - 2]) + 3)

        if arr[0][N-2]+arr[0][N-1]<=W:
            DP[N-1]=[min(DP[N-2][1], min(DP[N-3])+2), inf, inf, min(DP[N-2])+1]
        else : DP[N-1]=[inf, inf, inf, min(DP[N-2])+1]

        ans = min(min(DP[N - 1]), ans)

    print(ans)
