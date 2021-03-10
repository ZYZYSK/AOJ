from sys import stdin
INFTY=1<<30
def postorder(g,root,ans):
    if(root==-1):return
    postorder(g,g[root][0],ans)
    postorder(g,g[root][1],ans)
    ans.append(root)
def make_node(g,pre,inn):
    if len(pre)==0:return
    pre_l=[];pre_r=[];inn_l=[];inn_r=[]
    root=pre[0]
    inn_root=inn.index(pre[0])
    inn_l=inn[0:inn_root]
    inn_r=inn[inn_root+1:]
    i=1
    while i<len(pre) and pre[i] in inn_l:
        i+=1
    pre_l=pre[1:i];pre_r=pre[i:]
    if len(pre_l):g[root][0]=pre_l[0]
    if len(pre_r):g[root][1]=pre_r[0]
    make_node(g,pre_l,inn_l)
    make_node(g,pre_r,inn_r)
n=int(input())
g=[[-1,-1] for i in range(n+1)]
pre=list(map(int,input().split()))
inn=list(map(int,input().split()))
make_node(g,pre,inn)
ans=[]
postorder(g,pre[0],ans)
print(*ans,sep=' ')