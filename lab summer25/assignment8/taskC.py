import sys
sys.stdin = open("input.txt","r")

class UnionFind:
    def __init__(self,n):
        self.parent = list(range(n+1))
        self.rank = [1]*(n+1)
    
    def find(self,u):
        if self.parent[u]!=u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    
    def union(self,u,v):
        pu,pv = self.find(u),self.find(v)
        if pu==pv:
            return False
        if self.rank[pu]>self.rank[pv]:
            self.parent[pv] = pu
        elif self.rank[pv]>self.rank[pu]:
            self.parent[pu] = pv
        else:
            self.parent[pv] = pu
            self.rank[pu]+=1
        return True

def mst_kruskal(n,edges):
    uf = UnionFind(n+1)
    mst_weight = 0
    mst_edges = []
    non_mst_edges = []
    for w,u,v in edges:
        if uf.union(u,v):
            mst_weight += w
            mst_edges.append((u,v,w))
        else:
            non_mst_edges.append((u,v,w))
    if len(mst_edges) != n-1:
        return None, None, None
    return mst_weight, mst_edges, non_mst_edges

def second_mst(mst_edges, non_mst_edges,mst_weigth, nth):
    uf = UnionFind(len(mst_edges)+1)
    second_mst_weight = 0
    for i,(u,v,w) in enumerate(mst_edges):
        if i==nth:
            continue
        uf.union(u,v)
        second_mst_weight += w
    for u,v,w in non_mst_edges:
        if w+second_mst_weight == mst_weigth:
            continue
        if uf.union(u,v):
            second_mst_weight += w
            return second_mst_weight
    return None

def solve():
    n,m = list(map(int,input().split()))
    edges = []
    for _ in range(m):
        u,v,w = list(map(int,input().split()))
        edges.append((w,u,v))
    edges.sort()
    mst_weight, mst_edges, non_mst_edges = mst_kruskal(n,edges)
    if mst_weight==None:
        print("-1")
        return
    second_mst_weight = float('inf')
    for i in range(len(mst_edges)):
        current_weight = second_mst(mst_edges, non_mst_edges,mst_weight, i)
        if current_weight is not None:
            second_mst_weight = min(second_mst_weight, current_weight)
    print(second_mst_weight if second_mst_weight != float('inf') else "-1")
t=1
t = int(input())
while t>0:
    t-=1
    solve()