import sys
sys.stdin = open("input.txt","r")

def solve():
    n,m = list(map(int,input().split()))
    mat = [[0]*(n+1) for _ in range(n+1)]
    for _ in range(m):
        u,v,w = list(map(int,input().split()))
        mat[u][v] = w
    for i in range(1,n+1):
        for j in range(1,n+1): print(mat[i][j],end=(' ' if j!=n else '\n'))

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()