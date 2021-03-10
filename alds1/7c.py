from sys import stdin
INFTY=1<<30
def get_root(a,n):
    for i in range(n):
        if a[i]==-1:
            return i
def preorder(g,root):
    if(root==-1):return
    print(f' {root}',end='')
    preorder(g,g[root][0])
    preorder(g,g[root][1])
def inorder(g,root):
    if(root==-1):return
    inorder(g,g[root][0])
    print(f' {root}',end='')
    inorder(g,g[root][1])
def postorder(g,root):
    if(root==-1):return
    postorder(g,g[root][0])
    postorder(g,g[root][1])
    print(f' {root}',end='')

n=int(input())
g=[[] for i in range(n)]
p=[-1 for i in range(n)]
for _ in range(n):
    id,lid,rid=list(map(int,input().split()))
    g[id]=[lid,rid]
    if lid!=-1:p[lid]=id
    if rid!=-1:p[rid]=id

root=get_root(p,n)
print("Preorder")
preorder(g,root)
print('\nInorder')
inorder(g,root)
print('\nPostorder')
postorder(g,root)
print()