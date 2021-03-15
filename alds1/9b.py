from sys import stdin
INFTY=1<<30
def maxHeapify(H,n,i):
    l=i*2;r=i*2+1
    if l<=n and H[l]>H[i]:
        largest=l
    else:
        largest=i
    if r<=n and H[r]>H[largest]:
        largest=r
    if largest!=i:
        H[i],H[largest]=H[largest],H[i]
        maxHeapify(H,n,largest)
def buildMaxHeap(H,n):
    for i in range(n//2,0,-1):
        maxHeapify(H,n,i)
n=int(input())
H=list(map(int,stdin.readline().split()))
H=[0]+H
buildMaxHeap(H,n)
print(' ',end='')
print(*H[1:],sep=' ')
