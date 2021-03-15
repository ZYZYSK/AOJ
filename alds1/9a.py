from sys import stdin
INFTY=1<<30
def getParent(h,i):
    p=(i+1)//2-1
    return '' if p<0 else f'parent key = {h[p]}, '
def getLeft(h,i):
    p=(i+1)*2-1
    return '' if p>=len(h) else f'left key = {h[p]}, '
def getRight(h,i):
    p=(i+1)*2+1-1
    return '' if p>=len(h) else f'right key = {h[p]}, '
def solver(h,n):
    for i in range(n):
        print(f'node {i+1}: key = {h[i]}, {getParent(h,i)}{getLeft(h,i)}{getRight(h,i)}')
n=int(input())
h=list(map(int,stdin.readline().split()))
solver(h,n)