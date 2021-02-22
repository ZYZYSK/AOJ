import math
def countPrime(a):
    ans=0
    for i in a:
        flag=True
        for j in range(2,int(math.sqrt(i))+1):
            if i%j==0:
                flag=False
                break
        if flag:
            ans+=1
    return ans
n=int(input())
a=[int(input()) for i in range(n)]
print(countPrime(a))