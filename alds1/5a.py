def solver(n,a,m):
    nlist=set()
    for i in range(1,(1<<n)):
        l=[]
        for j in range(n):
            if i&(1<<j):
                l.append(a[j])
        ans=0
        for j in l:
            ans+=j
        nlist.add(ans)
    for i in m:
        print('yes') if i in nlist else print('no')


n=int(input())
a=[int(i) for i in input().split()]
q=int(input())
m=[int(i) for i in input().split()]
solver(n,a,m)