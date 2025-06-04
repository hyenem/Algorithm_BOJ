def solution(num):
    global ans
    if num>B: return

    if num>=A:
        ans += 1
        
    for n in (4, 7):
        solution(num*10+n)

A, B = map(int, input().split())
ans = 0
solution(0)
print(ans)