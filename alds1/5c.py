import math
from sys import stdin
INFTY=1<<30
def makepoint(lx,ly,rx,ry,n):
    if n==0:return
    sx=lx+(rx-lx)/3;sy=ly+(ry-ly)/3
    tx=lx+(rx-lx)*2/3;ty=ly+(ry-ly)*2/3
    ux=sx+(tx-sx)/2-math.sqrt(3)*(ty-sy)/2
    uy=sy+math.sqrt(3)*(tx-sx)/2+(ty-sy)/2
    n-=1
    makepoint(lx,ly,sx,sy,n)
    printf(sx,sy)
    makepoint(sx,sy,ux,uy,n)
    printf(ux,uy)
    makepoint(ux,uy,tx,ty,n)
    printf(tx,ty)
    makepoint(tx,ty,rx,ry,n)
def printf(x,y):
    print(f'{x} {y}')
def solver(n):
    printf(0,0)
    makepoint(0,0,100,0,n)
    printf(100,0)
n=int(input())
solver(n)
