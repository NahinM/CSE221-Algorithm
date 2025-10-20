import sys
sys.stdin = open("input.txt","r")

def solve():
    n = int(input())
    x,y = list(map(int,input().split()))
    dx = [-1,-1,-1,0,0,1,1,1]
    dy = [-1,0,1,-1,1,-1,0,1]
    ans = []
    for i in range(8):
        xx = x+dx[i]
        yy = y+dy[i]
        if 0<xx<=n and 0<yy<=n: ans.append((xx,yy))
    print(len(ans))
    for xx,yy in ans: print(xx,yy)


t = 1
# t = int(input())
while t>0:
    t-=1
    solve()