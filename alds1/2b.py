def selectionSort(a,n):
    ans=0
    for i in range(n):
        j=i
        for k in range(i,n):
            if a[k]<a[j]:
                j=k
        if i!=j:
            a[i],a[j]=a[j],a[i]
            ans+=1
    return ans
n=int(input())
a=[int(i) for i in input().split()]
ans=selectionSort(a,n)
print(*a,sep=' ')
print(ans)