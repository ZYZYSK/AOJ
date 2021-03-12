from sys import stdin
INFTY=1<<30
class node:
    def __init__(self,value) -> None:
        self.value=value
        self.left=None
        self.right=None
class tree:
    def __init__(self) -> None:
        self.root=None
    def insert(self,value):
        p=self.root
        q=None
        x=node(value)
        while not p is None:
            q=p
            if value<p.value:
                p=p.left
            else:
                p=p.right
        if q is None:
            self.root=x
        elif value<q.value:
            q.left=x
        else:
            q.right=x
    def print_pre(self,p):
        if p is None:return
        print(f' {p.value}',end='')
        self.print_pre(p.left)
        self.print_pre(p.right)
    def print_inn(self,p):
        if p is None:return
        self.print_inn(p.left)
        print(f' {p.value}',end='')
        self.print_inn(p.right)

    def print(self):
        self.print_inn(self.root)
        print()
        self.print_pre(self.root)
        print()
m=int(input())
T=tree()
for _ in range(m):
    order=stdin.readline().split()
    if order[0]=="insert":
        T.insert(int(order[1]))
    else:
        T.print()
