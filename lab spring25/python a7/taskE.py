from queue import PriorityQueue as PQ
import sys
sys.stdin = open("input.txt","r")

def mkgraph(graph,m):
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    w = list(map(int,input().split()))
    for i in range(m):
        graph[u[i]].append((v[i],w[i]))

def dijkstra(graph,n):
    pq = PQ([(0,1,0),(0,1,1)])
    dst = [float('inf')]*(n+1)
    dst[1] = 0

    while pq:
        d,at,p = pq.get()
        for u,w in graph[at]:
            cost = d+w
            if cost < dst[u]:
                dst[u] = cost
                pq.put((cost,u,w))
    
    print(dst[n])



def solve():
    n,m = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    mkgraph(graph,m)
    # print(graph)
    dijkstra(graph,n)


t = 1
t = int(input())
while t>0:
    solve()
    t-=1