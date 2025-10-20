import sys
sys.stdin = open("input.txt","r")

def fastMod(dp,a,n,m):
    if n<=1: return a
    if dp.get(n) != None: return dp[n]
    x = fastMod(dp,a,n>>1,m)
    dp[n>>1] = x
    if n&1: return ((x*x)%m*a)%m
    else: return (x*x)%m

def driftMod(dp,a,n,m):
    if n<=1: return a
    sln = driftMod(dp,a,n>>1,m)
    an = fastMod(dp,a,n>>1,m)
    ann = fastMod(dp,a,n,m)
    if n&1: return (sln+an*sln +ann)%m
    else: return (sln+an*sln)%m


def solve():
    a,n,m = list(map(int,input().split()))
    dp = {}
    print(driftMod(dp,a%m,n,m))



t = 1
t = int(input())
while t!=0:
    solve()
    t-=1