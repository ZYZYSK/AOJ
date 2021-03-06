def solver(n,s,q,t):
    t.sort()
    i=0
    j=0
    ans=0
    while i<q and j<n:
        if t[i]<s[j]:
            i+=1
        elif t[i]==s[j]:
            i+=1
            j+=1
            ans+=1
        elif t[i]>s[j]:
            j+=1
    return ans
n=int(input())
s=[int(i) for i in input().split()]
q=int(input())
t=[int(i) for i in input().split()]
print(solver(n,s,q,t))