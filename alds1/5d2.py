from sys import stdin
INFTY=1<<32
class fenwick_tree:
    def __init__(self,m) -> None:
        self.m=m
        self.bit=[0]*(m+1)
    def add(self,i,w):
        while i<=self.m:
            self.bit[i]+=w
            i+=i&-i
    def sum(self,i):
        ret=0
        while i>0:
           ret+=self.bit[i]
           i-=(i&-i)
        return ret

cnt=0
n=int(input())
a=[int(i) for i in stdin.readline().split()]
d={n: i for i,n in enumerate(sorted(a),start=1)}
a=[d[n] for n in a]
t=fenwick_tree(n)
for i in range(n):
    cnt+=(i-t.sum(a[i]))
    t.add(a[i],1)
print(cnt)