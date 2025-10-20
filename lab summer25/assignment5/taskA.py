import sys
from collections import deque

sys.stdin = open("input.txt","r")

def bfs(graph,n,start=1):
    q = deque()
    visited = [False]*(n+1)
    q.append(start)
    visited[start] = True

    while q:
        at = q.popleft()
        print(at, end=' ')
        for v in graph[at]:
            if not visited[v]:
                q.append(v)
                visited[v]=True


def solve():
    n,m = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
        graph[v].append(u)
    bfs(graph,n)

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()