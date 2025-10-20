import sys
sys.stdin = open("input.txt","r")

def solve():
    n,m = list(map(int,input().split()))
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    ans = [0]*(n+1)
    for i in range(m):
        ans[v[i]]+=1
        ans[u[i]]-=1
    for i in range(1,n+1): print(ans[i],end=' ')
    print()


t = 1
t = int(input())
while t>0:
    t-=1
    solve()