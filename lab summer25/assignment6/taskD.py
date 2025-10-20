import sys
from collections import deque

sys.stdin = open("input.txt","r")

def bfs(graph,n,s=1):
    visited = [False]*(n+1)
    q = deque()
    visited[s] = True
    q.append((s,0))
    depth,ans = 0,s
    
    while q:
        at,d = q.popleft()
        for v in graph[at]:
            if not visited[v]:
                visited[v] = True
                q.append((v,d+1))
                if depth<d+1:
                    depth = d+1
                    ans = v
    return ans,depth

def solve():
    n = int(input())
    graph = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
        graph[v].append(u)
    
    a,d = bfs(graph,n)
    b,d = bfs(graph,n,a)
    print(d)
    print(a,b)

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()