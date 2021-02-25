from sys import stdin
from collections import deque
class blist:
    def __init__(self) -> None:
        self.blist=deque()
    def insert(self,x):
        self.blist.appendleft(x)
    def delete(self,x):
        try:
            self.blist.remove(x)
        except ValueError:
            pass
    def deleteFirst(self):
        self.blist.popleft()
    def deleteLast(self):
        self.blist.pop()
n=int(input())
l=blist()
for i in range(n):
    cmd=stdin.readline()[:-1].split()
    if cmd[0]=='insert':
        l.insert(cmd[1])
    elif cmd[0]=='delete':
        l.delete(cmd[1])
    elif cmd[0]=='deleteFirst':
        l.deleteFirst()
    else:
        l.deleteLast()
print(*l.blist,sep=' ')
