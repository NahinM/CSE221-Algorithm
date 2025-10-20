import sys
sys.stdin = open("input.txt","r")

def dfs(graph,root,tree_size,visited):
    visited[root] = True
    if tree_size[root] != 0: return tree_size[root]
    size = 1
    for v in graph[root]:
        if not visited[v]: size += dfs(graph,v,tree_size,visited)
    tree_size[root] = size
    return size

def solve():
    n,r = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
        graph[v].append(u)
    tree_size = [0]*(n+1)
    visited = [False]*(n+1)
    dfs(graph,r,tree_size,visited)
    for _ in range(int(input())): print(tree_size[int(input())])

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()