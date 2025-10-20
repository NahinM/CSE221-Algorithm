import sys
from collections import deque

sys.stdin = open("input.txt","r")

def bfs(graph,n,s,d):
    if s==d:
        path = deque()
        path.append(s)
        return 0,path

    q = deque()
    visited = [False]*(n+1)
    q.append(s)
    visited[s] = True
    parent = [0]*(n+1)
    found = False
    while q:
        at = q.popleft()
        for v in graph[at]:
            if visited[v]: continue
            visited[v] = True
            q.append(v)
            parent[v] = at
            found = (v==d)
            if found: break
        if found: break
    
    if not found: return (-1,None)
    path = deque()
    at = d
    while parent[at]!=0:
        path.append(at)
        at = parent[at]
    path.append(s)
    return len(path)-1,path

def solve():
    n,m,s,d,k = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
    
    len_sk,sk = bfs(graph,n,s,k)
    len_kd,kd = bfs(graph,n,k,d)
    if len_sk<0 or len_kd<0:
        print('-1')
        return
    print(len_sk+len_kd)
    for _ in range(len_sk): print(sk.pop(), end=" ")
    while kd: print(kd.pop(), end=" ")

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()