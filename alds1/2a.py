def bubbleSort(a,n):
    flag=1
    ans=0
    while flag:
        flag=0
        for j in range(n-1,0,-1):
            if(a[j]<a[j-1]):
                a[j],a[j-1]=a[j-1],a[j]
                flag=1
                ans+=1
    print(*a,sep=' ')
    print(ans)


n=int(input())
a=[int(i) for i in input().split()]
bubbleSort(a,n)