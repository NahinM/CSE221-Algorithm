import sys 
sys.stdin = open("input.txt","r")



def solve():
    n = int(input())
    a1 = list(map(int,input().split()))
    m = int(input())
    a2 = list(map(int,input().split()))

    i,j=0,0
    while i<n and j<m:
        if a1[i]<a2[j]:
            print(a1[i], end=" ")
            i+=1
        else:
            print(a2[j], end=" ")
            j+=1

    for ii in range(i,n): print(a1[ii], end=" ")
    for jj in range(j,m): print(a2[jj], end=" ")

t = 1
t = int(input())
while t:
    solve()
    t-=1
    print()