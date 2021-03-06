def solver(n,s,q,t):
    ns=set()
    for i in s:
        ns.add(i)
    ans=0
    for i in t:
        if i in s:
            ans+=1
    return ans
n=int(input())
s=[int(i) for i in input().split()]
q=int(input())
t=[int(i) for i in input().split()]
print(solver(n,s,q,t))
