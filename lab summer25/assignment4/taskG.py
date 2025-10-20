import sys
sys.stdin = open("input.txt","r")

def solve():
    n,m,k = list(map(int,input().split()))
    board = list([False]*(n+1) for _ in range(n+1))
    dx = [-2,-2,-1,-1,1,1,2,2]
    dy = [-1,1,-2,2,-2,2,-1,1]
    attack = False
    pos = []
    for _ in range(k):
        x,y = list(map(int,input().split()))
        pos.append((x,y))
        board[x][y] = True
    for x,y in pos:
        if attack: break
        for i in range(8):
            if attack: break
            xx = x+dx[i]
            yy = y+dy[i]
            if 0<xx<=n and 0<yy<=m and board[xx][yy]: attack = True
    print("YES") if attack else print("NO")

t = 1
t = int(input())
while t>0:
    t-=1
    solve()