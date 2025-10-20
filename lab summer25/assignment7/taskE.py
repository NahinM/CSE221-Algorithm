import heapq,sys
sys.stdin = open("input.txt","r")
from collections import deque


def dijkstra(graph,n,s,d):
    INF = 9223372036854775807
    pq = []
    dist = [[INF]*(n+1) for _ in range(2)]
    dist[0][1] = 0
    dist[1][1] = 0
    heapq.heappush(pq,(0,s,0))
    heapq.heappush(pq,(0,s,1))

    while pq:
        ds,at,p = heapq.heappop(pq)
        for v,w in graph[at]:
            if (p+w)%2==0: continue
            c = p%2
            dd = ds+w
            if dist[c][v]>dd:
                dist[c][v] = dd
                heapq.heappush(pq,(dd,v,w))

    ans = min(dist[0][n],dist[1][n])
    print("-1") if ans==INF else print(ans)

def solve():
    n,m = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    w = list(map(int,input().split()))
    for i in range(m):
        graph[u[i]].append((v[i],w[i]))
    dijkstra(graph,n,1,n)
    
t=1
t = int(input())
while t>0:
    t-=1
    solve()
    print()