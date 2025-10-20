import sys
sys.stdin = open("input.txt","r")


inver = 0
def merge(arr, a, b):
    global inver
    i,j,at=0,0,0
    l1,l2 = len(a),len(b)
    
    while i<l1 and j<l2:
        if a[i]<=b[j]:
            arr[at] = a[i]
            i+=1
        else:
            arr[at] = b[j]
            inver += (l1-i)
            j+=1
        at+=1

    while i<l1:
        arr[at] = a[i]
        i+=1
        at+=1
    while j<l2:
        arr[at] = a[j]
        j+=1
        at+=1


def mergeSort(arr):
    if len(arr) <= 1:
        return
    else:
        mid = len(arr)//2
        a1 = arr[:mid]
        mergeSort(a1)
        a2 = arr[mid:]
        mergeSort(a2)
        merge(arr, a1, a2)

n = int(input())
arr = list(map(int,input().split()))

mergeSort(arr)
print(inver)
print(arr)