import sys
from collections import deque

sys.stdin = open("input.txt","r")

def solve():
    n,m = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    deg = [0]*(n+1)
    for _ in range(m):
        a,b = list(map(int,input().split()))
        graph[a].append(b)
        deg[b]+=1
    
    path = deque()
    q= deque()
    for i in range(1,n+1):
        if deg[i]==0:
            path.append(i)
            q.append(i)

    # top sort ->
    while q:
        at = q.popleft()
        deg[at] = -1
        for v in graph[at]:
            deg[v]-=1
            if deg[v]==0:
                q.append(v)
                path.append(v)
    # end top sort

    for i in range(1,n+1):
        if deg[i]>0:
            print("-1")
            return
        
    while path:
        print(path.popleft(), end=' ')

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()