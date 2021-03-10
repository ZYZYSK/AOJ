from sys import stdin
INFTY=1<<30
n=int(input())
g=[[] for i in range(n)]
p=[-1 for i in range(n)]
d=[INFTY for i in range(n)]
type=["" for i in range(n)]
for _ in range(n):
    t=list(map(int,input().split()))
    id=t[0];k=t[1];c=t[2:]
    type[id]="leaf" if len(c)==0 else "internal node"
    for idc in c:
        g[id].append(idc)
        p[idc]=id
for i in range(n):
    if p[i]==-1:
        type[i]="root"
        d[i]=0
        stk=[i]
        while len(stk):
            parent=stk.pop()
            for child in g[parent]:
                d[child]=d[parent]+1
                stk.append(child)
        break

for i in range(n):
    print(f'node {i}: parent = {p[i]}, depth = {d[i]}, {type[i]}, {g[i]}')
