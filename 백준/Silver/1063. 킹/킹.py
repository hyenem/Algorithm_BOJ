dic = {
    'R': (0, 1), 'L':(0, -1), 'B':(-1, 0), 'T':(1, 0), 'RT':(1, 1), 'LT':(1, -1), 'RB':(-1, 1), 'LB':(-1, -1)
}

l1, l2, N  = input().split()
king = [int(l1[1])-1, ord(l1[0])-ord('A')]
rock = [int(l2[1])-1, ord(l2[0])-ord('A')]

for _ in range(int(N)):
    direction = input()
    kx = king[0]+dic[direction][0]
    ky = king[1] + dic[direction][1]
    if 0<=kx<8 and 0<=ky<8:
        if kx==rock[0] and ky==rock[1]:
            rx = rock[0]+dic[direction][0]
            ry = rock[1]+dic[direction][1]
            if 0<=rx<8 and 0<=ry<8:
                rock[0], rock[1]= rx, ry
                king[0], king[1] = kx, ky
        else :
            king[0], king[1] = kx, ky
print(chr(king[1]+ord('A'))+str(king[0]+1))
print(chr(rock[1]+ord('A'))+str(rock[0]+1))