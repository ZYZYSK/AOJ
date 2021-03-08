from sys import stdin
def solver(n,k,w):
    #合計重量
    sum=0
    for i in w:
        sum+=i
    ans=sum
    #二分探索
    l=1;r=sum;m=(l+r)//2
    while l<=r:
        cnt=0
        i=0
        ansflag=True
        while i<n:
            tmp=0
            while i<n and tmp+w[i]<=m:
                tmp+=w[i]
                i+=1
            if tmp==0:
                ansflag=False
                break
            cnt+=1
        if cnt>k or not ansflag:
            l=m+1;m=(l+r)//2
        else:
            ans=m
            r=m-1;m=(l+r)//2
    return ans



n,k=[int(i) for i in input().split()]
w=[int(stdin.readline()) for i in range(n)]
# w=[int(input()) for i in range(n)]
print(solver(n,k,w))