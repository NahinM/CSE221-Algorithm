import heapq,sys
sys.stdin = open("input.txt","r")
from collections import deque

def path(parent,d):
    p = deque()
    while d!=0:
        p.append(d)
        d = parent[d]
    while p: print(p.pop(), end=" ")

def dijkstra(graph,n,s,d):
    INF = 9223372036854775807
    visited = [False]*(n+1)
    pq = []
    dist = [INF]*(n+1)
    dist[s]=0
    parent = [0]*(n+1)
    heapq.heappush(pq,(0,s))

    while pq:
        ds,at = heapq.heappop(pq)
        visited[at] = True
        if at==d: break
        if dist[at]<ds: continue
        for v,w in graph[at]:
            if visited[v]: continue
            dd = ds+w
            if dist[v]>dd:
                dist[v] = dd
                heapq.heappush(pq,(dd,v))
                parent[v] = at
    if dist[d]==INF:
        print("-1")
        return
    print(dist[d])
    path(parent,d)

def solve():
    n,m,s,d = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    w = list(map(int,input().split()))
    for i in range(m):
        graph[u[i]].append((v[i],w[i]))
    dijkstra(graph,n,s,d)
    
t=1
t = int(input())
while t>0:
    t-=1
    solve()
    print()