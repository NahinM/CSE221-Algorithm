import heapq,sys

sys.stdin = open("input.txt","r")

def cmp(graph,deg,s1,s2):
    l1 = len(s1)
    l2 = len(s2)
    i=0
    prefix = l1>l2
    while i<min(l1,l2):
        p = ord(s1[i]) - ord('a')
        a = ord(s2[i]) - ord('a')
        if deg[p]==-1: deg[p] = 0
        if deg[a]==-1: deg[a] = 0
        if p!=a:
            deg[a]+=1
            graph[p].append(a)
            prefix = False
            break
        i+=1

    while i<max(l1,l2):
        if i<l1:
            a = ord(s1[i]) - ord('a')
            if deg[a]==-1: deg[a] = 0
        if i<l2:
            a = ord(s2[i]) - ord('a')
            if deg[a]==-1: deg[a] = 0
        i+=1
    return prefix

def solve():
    deg = [-1]*26
    graph = [[] for _ in range(26)]
    n = int(input())
    prev = input()
    flag = False
    for _ in range(n-1):
        next = input()
        flag |= cmp(graph,deg,prev,next)
        prev=next

    if flag:
        print("-1")
        return
    
    # top sort
    pq = []
    total = 0
    ans = ""
    for i in range(26):
        if deg[i]==0:
            heapq.heappush(pq,i)
        total+=(deg[i]>=0)
    while pq:
        at = heapq.heappop(pq)
        total-=1
        ans += (chr(at+ord('a')))
        for v in graph[at]:
            deg[v] -= 1
            if deg[v]==0:
                heapq.heappush(pq,v)
    if total:
        print("-1")
        return
    print(ans)

t = 1
t = int(input())
while t>0:
    t-=1
    solve()
    print()