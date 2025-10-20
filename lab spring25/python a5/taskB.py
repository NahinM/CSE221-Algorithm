import sys
sys.stdin = open("input.txt","r")
# sys.setrecursionlimit(2*100000+5)

def dfs(graph,vst,at):
    vst[at] = 1
    print(at,end=" ")
    for u in graph[at]: 
        if vst[u] == 0: dfs(graph,vst,u)

def solve():
    n,m = list(map(int,input().split()))
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))
    graph = [set() for _ in range(n+1)]
    for i in range(m):
        graph[u[i]].add(v[i])
        graph[v[i]].add(u[i])
    dfs(graph,[0]*(n+1),1)
    print()

t = 1
t = int(input())
while t!=0:
    t-=1
    solve()