import sys
sys.stdin = open("input.txt","r")

mx = 0
r,c=0,0
def valid(rr,cc):
    return 0<=rr<r and 0<=cc<c

def bfs(grid,vst,R,C):
    drc = [(-1,0),(0,1),(1,0),(0,-1)]
    global mx,r,c
    Q = [(R,C)]
    vst[R][C] = 1
    total = 1
    while len(Q)!=0:
        i,j = Q.pop(0)
        for ii,jj in drc:
            rr=i+ii
            cc=j+jj
            if(valid(rr,cc) and grid[rr][cc]!="#" and vst[rr][cc]==0):
                vst[rr][cc] = 1
                Q.append((rr,cc))
                if grid[rr][cc] == "D": total+=1
    
    mx = max(total,mx)


def solve():
    global mx,r,c
    mx = 0
    r,c = list(map(int,input().split()))
    grid = list()
    for _ in range(r):
        grid.append(input())

    vst = [[0]*c for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if grid[i][j] == 'D' and vst[i][j]==0: bfs(grid,vst,i,j)
    
    print(mx)

t=1
t = int(input())
while t!=0:
    t-=1
    solve()