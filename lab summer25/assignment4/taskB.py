import sys
sys.stdin = open("input.txt","r")

def solve():
    n,m = list(map(int,input().split()))
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    w = list(map(int,input().split()))
    mat = [[] for _ in range(n+1)]
    for i in range(m): mat[u[i]].append((v[i],w[i]))
    for i in range(1,n+1):
        print(f"{i}: ",end="")
        for e in mat[i]: print(e,end=' ')
        print()

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()