import heapq,sys

sys.stdin = open("input.txt","r")

def bfs(graph,distance,ss):
    pq= []
    for s in ss: heapq.heappush(pq,(0,s))
    while pq:
        d,at = heapq.heappop(pq)
        if distance[at]<d: continue
        for v in graph[at]:
            if d+1<distance[v]:
                heapq.heappush(pq,(d+1,v))
                distance[v] = d+1

def solve():
    n,m,S,Q = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
        graph[v].append(u)
    ss = list(map(int,input().split()))
    q = list(map(int,input().split()))

    distance = [(1<<31)]*(n+1)
    for i in range(S): distance[ss[i]] = 0
    bfs(graph,distance,ss)
    for i in range(Q):
        ans = distance[q[i]]
        print( ans if ans<(1<<31) else -1 , end=' ')

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()