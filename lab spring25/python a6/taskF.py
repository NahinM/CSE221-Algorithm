from heapq import heappush, heappop
def alien(li):
    inord,adj=ad(li)

    for i in range(len(li)-1):
        w1=li[i]
        w2=li[i+1]
        minlen=min(len(w1),len(w2))
        if w1[:minlen] == w2[:minlen] and len(w1) > len(w2):
            return "-1"
        for j in range(minlen):
            if w1[j] != w2[j]:
                adj[w1[j]].append(w2[j])
                inord[w2[j]] += 1
                break
    heap=[]
    res=""
    for i in inord:
        if inord[i]==0:
            heappush(heap,i)
    while heap:
        cur=heappop(heap)
        res+=cur
        for n in adj[cur]:
            inord[n]-=1
            if inord[n]==0:
              heappush(heap,n)
    if len(res)!=len(inord):
      return -1
    return  res

def ad(li):
    dic={}
    adj={}
    for i in li:
      for j in i:
        dic[j]=0
        adj[j]=[]
    return dic,adj

# n = int(input())
# li = [input().strip() for _ in range(n)]
li = ["gef", "gie", "hf", "hd", "hc", "ha"]
ans=alien(li)
print(ans)