INFTY=1<<30
from sys import stdin
def merge(a,l,m,r):
    # print(f'\n配列{l}~{r}: {id(a)}')
    # print('\t各要素(整列前):')
    # for i in a:
    #     print(f'\t\t{id(i)}: {i}')
    ll=a[l:m]
    rl=a[m:r]
    ll.append(INFTY)
    rl.append(INFTY)
    # print(f'\t左: {ll} 右: {rl}')
    i=0;j=0
    for k in range(l,r):
        # print(f'\t\tll[i]: {i} {ll[i]}, rl[j]: {j} {rl[j]}')
        if ll[i]<rl[j]:
            a[k]=ll[i]
            i+=1
        else:
            a[k]=rl[j]
            j+=1
    # print('\t各要素(整列後):')
    # for i in a:
    #     print(f'\t\t{id(i)}: {i}')
def mergeSort(a,l,r):
    global ans
    if l+1<r:
        m=(l+r)//2
        mergeSort(a,l,m)
        mergeSort(a,m,r)
        merge(a,l,m,r)
        ans+=(r-l)


n=int(input())
s=[int(i) for i in input().split()]
# print(f'初期状態: {id(s)}')
ans=0
mergeSort(s,0,n)
print(*(s),sep=' ')
print(ans)
