import heapq,sys
from collections import deque
sys.stdin = open("input.txt","r")

def bfs(graph,n,s,d):
    visited = [False]*(n+1)
    q = deque()
    q.append(s)
    visited[s]=True
    parent = [0]*(n+1)
    while q:
        at = q.popleft()
        found = False
        while graph[at]:
            v = heapq.heappop(graph[at])
            if visited[v]: continue
            q.append(v)
            visited[v] = True
            parent[v] = at
            found = (v==d)
            if found: break
        if found: break
    
    at = d
    path = deque()
    while parent[at] != 0:
        path.append(at)
        at = parent[at]
    
    if len(path)==0:
        print('-1')
        return
    print(len(path))
    print(s,end=' ')
    while path:
        print(path.pop() , end=' ')
    print()
        

def solve():
    n,m,s,d = list(map(int,input().split()))
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for i in range(m):
        heapq.heappush(graph[u[i]],v[i])
        heapq.heappush(graph[v[i]],u[i])
        # print(u[i],v[i])
    if s==d:
        print(f"0\n{s}")
        return
    bfs(graph,n,s,d)

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()