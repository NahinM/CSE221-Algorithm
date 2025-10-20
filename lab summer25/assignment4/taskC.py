import sys
sys.stdin = open("input.txt","r")

def solve():
    n = int(input())
    for _ in range(n):
        mat = [0]*n
        a = list(map(int,input().split()))
        for i in range(1,len(a)): mat[a[i]] = 1
        for i in range(n): print(mat[i],end=' ')
        print()


t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()