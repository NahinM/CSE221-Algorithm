import sys
sys.stdin = open("input.txt","r")

def solve():
    n,m = list(map(int,input().split()))
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    deg = [0]*(n+1)
    for i in range(m):
        deg[u[i]]+=1
        deg[v[i]]+=1
    odd = 0
    for i in range(1,n+1): odd+=(deg[i]&1)
    print("YES") if (odd in (0,2)) else print("NO")

t = 1
t = int(input())
while t>0:
    t-=1
    solve()