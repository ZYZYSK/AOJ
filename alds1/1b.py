def gcd(a,b):
    x0=min(a,b)
    x1=max(a,b)
    while 1:
        r=x1%x0
        x1=x0
        x0=r
        if r==0:
            break
    return x1
x,y=[int(i) for i in input().split()]
print(gcd(x,y))