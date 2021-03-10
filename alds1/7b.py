from sys import stdin
INFTY=1<<30
def get_depth(id):
    ans=0
    while p[id]!=-1:
        id=p[id]
        ans+=1
    return ans

n=int(input())
p=[-1 for i in range(n)]
s=[-1 for i in range(n)]
deg=[0 for i in range(n)]
dep=[-1 for i in range(n)]
h=[0 for i in range(n)]
type=["internal node" for i in range(n)]

for _ in range(n):
    id,lid,rid=list(map(int,input().split()))
    if lid!=-1:p[lid]=id;deg[id]=1
    if rid!=-1:p[rid]=id;deg[id]=1
    if lid!=-1 and rid!=-1: s[lid]=rid;s[rid]=lid;deg[id]=2
    if lid==-1 and rid==-1:type[id]="leaf"
for i in range(n):
    dep[i]=get_depth(i)
    if type[i]=="leaf":
        id=i
        while p[id]!=-1:
            h[p[id]]=max(h[p[id]],h[id]+1)
            id=p[id]
        id=-1
    if p[i]==-1:
        type[i]="root"

for i in range(n):
    print(f'node {i}: parent = {p[i]}, sibling = {s[i]}, degree = {deg[i]}, depth = {dep[i]}, height = {h[i]}, {type[i]}')
