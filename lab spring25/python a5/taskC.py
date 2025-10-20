import sys
sys.stdin = open("input.txt","r")

def getGraph(graph,m):
    u = list(map(int,input().split()))
    v = list(map(int,input().split()))

    for i in range(m):
        graph[u[i]].add(v[i])
        graph[v[i]].add(u[i])

def bfs(graph,prnt,n,s,d):
    vst = [False]*(n+1)
    vst[s] = True
    Q = [s]
    prnt[s]=s
    while bool(Q):
        at = Q.pop(0)
        for u in graph[at]:
            if not vst[u]:
                vst[u] = True
                Q.append(u)
                prnt[u] = at
                if u==d: return

def path(prnt,at):
    pth = []
    depth = -1
    while at!=prnt[at]:
        pth.append(at)
        at = prnt[at]
        depth+=1
    if at==prnt[at]:
        pth.append(at)
        depth+=1
    
    print(depth)
    while bool(pth):
        print(pth.pop(),end=" ")
    print()

def solve():
    n,m,s,d = list(map(int,input().split()))
    graph = [set() for _ in range(n+1)]
    prnt = [0]*(n+1)
    getGraph(graph,m)
    if s==d:
        print(f"0\n{s}")
        return
    bfs(graph,prnt,n,s,d)
    if prnt[d]==0:
        print(-1)
        return
    # print(graph)
    path(prnt,d)


t = 1
t = int(input())
while t!=0:
    t-=1
    solve()