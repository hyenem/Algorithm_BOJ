N, x, y = map(int, input().split())

ans = 0
while x!=0 or y!=0:
    ans += ((x//(2**(N-1)))*2+(y//(2**(N-1))))*(4**(N-1))
    x%=2**(N-1)
    y%=2**(N-1)
    N-=1

print(ans)