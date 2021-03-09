from sys import stdin
INFTY=1<<30
def partition(a,l,r):
    i=l-1
    for j in range(l,r):
        if a[j]<=a[r]:
            i+=1
            a[i],a[j]=a[j],a[i]
    a[i+1],a[r]=a[r],a[i+1]
    return i+1
n=int(input())
a=list(map(int,stdin.readline().split()))
m=partition(a,0,n-1)
for i in range(n):
    if i==m:
        print(f'[{a[i]}]',end=' ')
    elif i==n-1:
        print(a[i])
    else:
        print(a[i],end=' ')
