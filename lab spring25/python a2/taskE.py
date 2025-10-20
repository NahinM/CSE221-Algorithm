import sys 
sys.stdin = open("input.txt","r")

def search(x,y):
    n = len(arr)
    lw,hi=0,n-1
    first,last = 0,0

    while lw<=hi:
        mid = (lw+hi)>>1
        if arr[mid]==x:
            first = mid
            hi = mid-1
        elif arr[mid]<x:
            lw = mid+1
        else:
            first = mid
            hi = mid-1

    lw,hi=0,n-1
    while lw<=hi:
        mid = (lw+hi)>>1
        if arr[mid]==y:
            last = mid
            lw = mid +1
        elif arr[mid]<y:
            last = mid
            lw = mid+1
        else:
            hi = mid-1

    return last-first+1

n,q = list(map(int,input().split()))
arr = list(map(int,input().split()))
for _ in range(q):
    x,y = list(map(int,input().split()))
    print(search(x,y))

