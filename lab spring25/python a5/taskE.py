import sys
sys.stdin = open("input.txt","r")
# sys.setrecursionlimit(2*100000+5)

cycle = False

def dfs(graph,vst,rec,at):
    global cycle
    vst[at] = 1
    rec[at] = True
    for u in graph[at]:
        if vst[u] == 0:
            dfs(graph,vst,rec,u)
        elif rec[u]: cycle=True
    rec[at] = False

def solve():
    global cycle
    cycle = False
    n,m = list(map(int,input().split()))
    graph = [set() for _ in range(n+1)]
    for _ in range(m):
        u,v = list(map(int,input().split()))
        graph[u].add(v)
    visited = [0]*(n+1)
    for u in range(1,n+1):
        if visited[u]==0: dfs(graph,visited,[False]*(n+1),u)
    print("YES"if(cycle) else "NO")

t = 1
t = int(input())
while t!=0:
    t-=1
    solve()