import sys 
sys.stdin = open("input.txt","r")

def solve():
    n,k = list(map(int,input().split()))
    arr = list(map(int,input().split()))

    mxlen = 0
    sm = 0
    i,j=0,0

    while j<n:
        if sm+arr[j]<=k:
            sm+=arr[j]
            mxlen = max(mxlen,j-i+1)
            j+=1
        elif sm!=0:
            sm-=arr[i]
            i+=1
        else:
            i+=1
            j+=1
    
    print(mxlen)

t = 1
t = int(input())
while t:
    solve()
    t-=1
    print()