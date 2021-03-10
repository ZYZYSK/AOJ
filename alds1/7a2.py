from sys import stdin
INFTY=1<<30
n=int(input())
g=[[] for i in range(n)]
p=[-1 for i in range(n)]
type=["internal node" for i in range(n)]
def get_depth(id):
    ans=0
    while p[id]!=-1:
        id=p[id]
        ans+=1
    return ans
for _ in range(n):
    t=list(map(int,input().split()))
    id=t[0];k=t[1];g[id]=t[2:]
    if len(g[id])==0:type[id]="leaf" 
    for idc in g[id]:
        p[idc]=id
for i in range(n):
    if p[i]==-1:
        type[i]="root"
        break
        

for i in range(n):
    print(f'node {i}: parent = {p[i]}, depth = {get_depth(i)}, {type[i]}, {g[i]}')

