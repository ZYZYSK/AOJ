from sys import stdin
INFTY=1<<30
def solver(a,n,k):
    c=[0 for i in range(k+1)]
    b=[0 for i in range(n)]
    for i in range(n):
        c[a[i]]+=1
    for i in range(1,k+1):
        c[i]+=c[i-1]
    for i in range(n):
        b[c[a[i]]-1]=a[i]
        c[a[i]]-=1
    return b

n=int(input())
a=[int(i) for i in stdin.readline().split()]
print(*(solver(a,n,max(a))),sep=' ')
