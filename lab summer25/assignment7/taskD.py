import sys
sys.stdin = open("input.txt","r")

def solve():
    n,m = list(map(int,input().split()))

    
t=1
t = int(input())
while t>0:
    t-=1
    solve()