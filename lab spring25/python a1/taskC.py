
def bubbleSort(arr,n):
    for i in range(n-1):

        for j in range(n-1-i):
            if arr[j][0] > arr[j+1][0]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
            elif arr[j][0] == arr[j+1][0] and int(arr[j][2])*60+int(arr[j][3])<int(arr[j+1][2])*60+int(arr[j+1][3]):
                arr[j],arr[j+1] = arr[j+1],arr[j]


n = int(input())
arr = []
for _ in range(n):
    name,w1,w2,w3,dst,w4,time = input().split()
    m,s = time.split(':')
    arr.append([name,dst,m,s])

bubbleSort(arr,n)
for name,dst,m,s in arr:
    print(f"{name} will departure for {dst} at {m}:{s}")