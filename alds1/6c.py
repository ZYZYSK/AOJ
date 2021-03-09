from sys import stdin
INFTY=1<<30
def partition(a,l,r):
    i=l-1
    for j in range(l,r):
        if a[j][1]<=a[r][1]:
            i+=1
            a[i],a[j]=a[j],a[i]
    a[i+1],a[r]=a[r],a[i+1]
    return i+1
def quickSort(a,l,r):
    if l<r:
        m=partition(a,l,r)
        quickSort(a,l,m-1)
        quickSort(a,m+1,r)
def make_card(x,i):
    x=x.split()
    return [x[0],int(x[1]),i]
def isStable(a,n):
    for i in range(n):
        while i<n-1 and a[i][1]==a[i+1][1]:
            if a[i][2]>a[i+1][2]:
                return False 
            i+=1
    return True
n=int(input())
a=[make_card(stdin.readline(),i) for i in range(n)]
quickSort(a,0,n-1)
print('Stable') if isStable(a,n) else print('Not stable')
for i in a:
    print(f'{i[0]} {i[1]}')