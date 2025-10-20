import heapq,sys
sys.stdin = open("input.txt","r")

def dijkstra(graph,n,s,d):
    INF = 9223372036854775807
    pq = []
    dist = [[INF]*(n+1),[INF]*(n+1)]
    dist[0][s] = 0
    heapq.heappush(pq,(0,s))

    while pq:
        ds,at = heapq.heappop(pq)
        for v,w in graph[at]:
            dd = ds+w
            if dd<dist[0][v]:
                dist[1][v] = dist[0][v]
                dist[0][v] = dd
                heapq.heappush(pq,(dd,v))
            if dist[0][v]<dd<dist[1][v]:
                dist[1][v] = dd
                heapq.heappush(pq,(dd,v))
    print("-1") if dist[1][d]==INF else print(dist[1][d])


def solve():
    n,m,s,d = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        u,v,w = list(map(int,input().split()))
        graph[u].append((v,w))
        graph[v].append((u,w))
    dijkstra(graph,n,s,d)

    
t=1
t = int(input())
while t>0:
    t-=1
    solve()