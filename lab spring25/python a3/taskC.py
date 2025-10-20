import sys
sys.stdin = open("input.txt","r")

def fastMod(a,b):
    if b<=1: return a

    x = fastMod(a,b>>1)
    if b&1: return ((x*x)%107*a)%107
    else: return (x*x)%107

a,b = list(map(int,input().split()))
print(fastMod(a%107,b))