import sys
sys.setrecursionlimit(2*100000+5)
sys.stdin = open("input.txt","r")

def dfs(graph,root,visited):
    visited[root] = 1
    ret = False
    for v in graph[root]:
        if visited[v] == 2: continue
        if visited[v] == 1: return True
        ret = ret or dfs(graph,v,visited)
        if ret: break
    visited[root] = 2
    return ret

def solve():
    n,m = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
    
    cycle = False
    visited = [0]*(n+1)
    for v in range(1,n+1):
        if visited[v]!=2: cycle = dfs(graph,v,visited)
        if cycle: break
    print("YES") if cycle else print("NO")

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()