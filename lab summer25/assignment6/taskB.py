import sys
from collections import deque

sys.stdin = open("input.txt","r")

def bfs(graph,color,s):
    color[s] = 1
    odd,even = 1,0
    q= deque()
    q.append(s)

    while q:
        at = q.popleft()
        for v in graph[at]:
            if color[v]!=-1: continue
            color[v] = 1-color[at]
            q.append(v)
            if color[v]==1: odd+=1
            else: even+=1
    return max(odd,even)

def solve():
    n,m = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
        graph[v].append(u)

    color = [-1]*(n+1)
    ans = 0
    for i in range(1,n+1):
        if color[i]==-1: ans += bfs(graph,color,i)
    print(ans)

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()