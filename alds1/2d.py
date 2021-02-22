def insertionSort(a,n,g,cnt):
    for i in range(g,n):
        v=a[i]
        j=i-g
        while j>=0 and a[j]>v:
            a[j+g]=a[j]
            j-=g
            cnt+=1
        a[j+g]=v
    return cnt
def shellSort(a,n):
    cnt=0
    ans=0
    m=n-1
    g=[]
    while m:
        cnt=insertionSort(a,n,m,cnt)
        g.append(m)
        ans+=1
        m//=2
    if len(g)==0:
        g.append(n)
        ans=1
    return ans,g,cnt
n=int(input())
a=[int(input()) for i in range(n)]
ans,g,cnt=shellSort(a,n)
print(ans)
print(*g,sep=' ')
print(cnt)
print(*a,sep='\n')
