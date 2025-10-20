import sys
# from collections import deque

sys.setrecursionlimit(2*100000+5)
sys.stdin = open("input.txt","r")

# def dfs(graph,n):
#     visited = [False]*(n+1)

#     for start in range(1,n+1):
#         if visited[start]: continue
#         stack = deque()
#         stack.append(start)

#         while stack:
#             at = stack[-1]
#             if not visited[at]: print(at,end=' ')
#             visited[at] = True
#             found = False
#             for v in graph[at]:
#                 if visited[v]: continue
#                 found = True
#                 stack.append(v)
#                 break
#             if not found: stack.pop()

def dfs(graph,root,visited):
    visited[root] = True
    print(root , end=' ')
    for v in graph[root]:
        if not visited[v]: dfs(graph,v,visited)

def solve():
    n,m = list(map(int,input().split()))
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    graph = [[] for _ in range(n+1)]
    for i in range(m):
        graph[u[i]].append(v[i])
        graph[v[i]].append(u[i])
    visited = [False]*(n+1)
    for v in range(1,n+1):
        if not visited[v]: dfs(graph,v,visited)

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()