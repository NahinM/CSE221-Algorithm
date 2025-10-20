import sys
from collections import deque

sys.stdin = open("input.txt","r")

def bfs(board,n,x1,y1,x2,y2):
    board[x1][y1] = 0
    if x1==x2 and y1==y2: return

    dx = [-2,-2,-1,-1,1,1,2,2]
    dy = [1,-1,2,-2,-2,2,-1,1]

    q = deque()
    q.append((x1,y1))
    
    while q:
        x,y = q.popleft()
        for i in range(8):
            xx,yy = dx[i]+x,dy[i]+y
            if 0<xx<=n and 0<yy<=n and board[xx][yy]==-1:
                board[xx][yy] = board[x][y]+1
                if xx==x2 and yy==y2: return
                q.append((xx,yy))


def solve():
    n = int(input())
    x1,y1,x2,y2 = list(map(int,input().split()))
    board = [[-1]*(n+1) for _ in range(n+1)]
    bfs(board,n,x1,y1,x2,y2)
    print(board[x2][y2])

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()