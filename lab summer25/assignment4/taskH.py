import math
import sys
sys.stdin = open("input.txt","r")

def solve():
    n,q = list(map(int,input().split()))
    graph = list([] for _ in range(n+1))

    for _ in range(q):
        x,k = list(map(int,input().split()))
        gi = graph[x]
        ln = len(gi)
        if ln >= k:
            print(gi[k-1])
            continue
        for i in range((gi[-1]+1 if ln>0 else 1),n+1):
            if i!=x and math.gcd(x,i)==1:
                gi.append(i)
                ln+=1
            if ln==k:
                print(gi[k-1])
                break
        if ln<k:
            print("-1")

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()