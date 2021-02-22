import copy
def BubbleSort(a,n):
    for i in range(n):
        for j in range(n-1,i,-1):
            if a[j][0][1]<a[j-1][0][1]:
                a[j],a[j-1]=a[j-1],a[j]
    return isStable(a,n)
def SelectionSort(a,n):
    for i in range(n):
        j=i
        for k in range(j,n):
            if a[k][0][1]<a[j][0][1]:
                j=k
        a[i],a[j]=a[j],a[i]
    return isStable(a,n)
def isStable(a,n):
    for i in range(n-1):
        j=i+1
        while j<n and a[i][0][1]==a[j][0][1]:
            if a[i][1]>a[j][1]:
                return False
            j+=1
    return True
def prt(a):
    l=[]
    for i in a:
        l.append(i[0])
    print(*l,sep=' ')
n=int(input())
_a=[i for i in input().split()]
a=[[_a[i],i] for i in range(n)]
b=copy.deepcopy(a)
bstable=BubbleSort(a,n)
prt(a)
print('Stable') if bstable else print('Not Stable')
sstable=SelectionSort(b,n)
prt(b)
print('Stable') if sstable else print('Not stable')