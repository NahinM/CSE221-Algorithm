import sys
from collections import deque

sys.stdin = open("input.txt","r")

def bfs(grid,r,h,i,j):
    dx = [-1,0,1,0]
    dy = [0,1,0,-1]

    q = deque()
    q.append((i,j))
    totalD = int(grid[i][j]=='D')
    grid[i][j] = '#'
    while q:
        i,j=q.popleft()
        for x in range(4):
            ii,jj = i+dx[x],j+dy[x]
            if 0<=ii<r and 0<=jj<h and grid[ii][jj] != '#':
                totalD+=int(grid[ii][jj]=='D')
                grid[ii][jj] = '#'
                q.append((ii,jj))
    return totalD

def solve():
    r,h = list(map(int,input().split()))
    grid = [[c for c in input()] for _ in range(r)]
    ans = 0
    for i in range(r):
        for j in range(h):
            if grid[i][j] == 'D': ans = max(ans,bfs(grid,r,h,i,j))
    print(ans)

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()