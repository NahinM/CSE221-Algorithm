import sys
sys.setrecursionlimit(2*100000+5)

def diameter(n,adj):
  st=dfs(adj,-1,1,0)
  final=dfs(adj,-1,st[1],0)
  return st[1],final[1],final[0]


def dfs(adj,p,start,distance):
  far=(distance ,start)
  for n in adj[start]:
    if n!=p:
      result=dfs(adj,start,n,distance+1)
      if far[0]<result[0]:
        far=result
  return far


def adj(n,li):
  ad={}
  for i in range(1,n+1):
    ad[i]=[]
  for i,j in li:
    ad[i].append(j)
    ad[j].append(i)
  return ad

n=int(input())
ed=[]
for i in range(n-1):
  ed.append(list(map(int,input().split())))

adjli=adj(n,ed)
res=diameter(n,adjli)
print(res[2])
print(res[0],res[1])