from sys import stdin
INFTY=1<<32
def merge(a,l,r,m):
    global cnt
    L=a[l:m]
    R=a[m:r]
    L.append(INFTY)
    R.append(INFTY)
    i=0;j=0
    for k in range(l,r):
        if(L[i]<=R[j]):
            a[k]=L[i]
            i+=1
        else:
            a[k]=R[j]
            j+=1
            cnt+=((m-l)-i)
def mergeSort(a,l,r):
    if r-l>1:
        m=(l+r)//2
        mergeSort(a,l,m)
        mergeSort(a,m,r)
        merge(a,l,r,m)

def solver(a,n):
    return mergeSort(a,0,n)
cnt=0
n=int(input())
a=[int(i) for i in input().split()]
solver(a,n)
print(cnt)