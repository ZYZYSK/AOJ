def solver(n,s,q,t):
    ans=0
    for i in t:
        l=0;r=n-1;m=(n-1)//2
        while l<=r:
            if i>s[m]:
                l=m+1;m=(l+r)//2
            elif i<s[m]:
                r=m-1;m=(l+r)//2
            elif i==s[m]:
                ans+=1
                break
    return ans
n=int(input())
s=[int(i) for i in input().split()]
q=int(input())
t=[int(i) for i in input().split()]
print(solver(n,s,q,t))