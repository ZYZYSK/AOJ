from sys import stdin
import time
INFTY=1<<30
class node:
    def __init__(self,key,priority) -> None:
        self.key=key
        self.priority=priority
        self.left=None
        self.right=None
class treap:
    def __init__(self) -> None:
        self.root=None
    #右回転
    def rightRotate(self,p):
        c=p.left
        p.left=c.right
        c.right=p
        return c
    #左回転
    def leftRotate(self,t):
        s=t.right
        t.right=s.left
        s.left=t
        return s
    #挿入
    def insert(self,key,priority):
        new=node(key,priority)
        p=self.root;q=None;pl=[]
        #挿入する場所までpを移動
        while not p is None:
            pl.append(p)
            q=p
            #重複したkeyは無視
            if key==p.key:
                return
            elif key<p.key:
                p=p.left
            else:
                p=p.right
        #TEST
        if len(pl)>0 and pl[len(pl)-1]!=q:print("エラー")
        #挿入
        if q is None:
            self.root=new
        elif key<q.key:
            q.left=new
        else:
            q.right=new
        while len(pl):
            r=pl.pop()
            #回転する必要がなければ終了
            if priority<r.priority:break
            #右回転
            if r.left==new:
                self.rightRotate(r)
            #左回転
            elif r.right==new:
                self.leftRotate(r)
            #回転した部分は切れてしまうのでつなげる
            if len(pl)==0:
                self.root=new
            else:
                v=pl[len(pl)-1]
                if key<v.key:v.left=new
                else:v.right=new
    #検索
    def find(self,key):
        p=self.root;q=None
        while not p is None:
            if key==p.key:return [p,q]
            elif key<p.key:q=p;p=p.left
            else:q=p;p=p.right
        return [None,None]
    #削除
    def delete(self,key):
        p,q=self.find(key)
        #削除する値が存在しなければ何もしない
        if p is None:return
        #削除
        while True:
            #つけかえない点
            r=q
            #削除する点が葉の場合
            if p.left is None and p.right is None:
                if q is None:self.root=None
                elif q.left==p:q.left=None
                else:q.right=None
                return
            #削除する点が右子だけを持つ場合
            elif p.left is None:
                q=self.leftRotate(p)
            #削除する点が左子だけを持つ場合
            elif p.right is None:
                q=self.rightRotate(p)
            #削除する点が2つの子を持つ場合
            else:
                if p.left.priority>p.right.priority:
                    q=self.rightRotate(p)
                else:
                    q=self.leftRotate(p)
            #回転した部分は切れてしまうのでつなげる
            #削除する点が根の場合，根を変更する
            if r==None:self.root=q
            else:
                if q.key<r.key:r.left=q
                else:r.right=q

    def _delete(self,t,key):
        if t.left==None and t.right is None:
            return None
        elif t.left is None:
            t=self.leftRotate(t)
        elif t.right is None:
            t=self.rightRotate(t)
        else:
            if t.left.priority>t.right.priority:
                t=self.rightRotate(t)
            else:
                t=self.leftRotate(t)
        return self.delete(t,key)
    def print_pre(self,p):
        if p is None:return
        print(f' {p.key}',end='')
        self.print_pre(p.left)
        self.print_pre(p.right)
    def print_inn(self,p):
        if p is None:return
        self.print_inn(p.left)
        print(f' {p.key}',end='')
        self.print_inn(p.right)

    def print(self):
        self.print_inn(self.root)
        print()
        self.print_pre(self.root)
        print()


            
m=int(input())
T=treap()
for _ in range(m):
    order=stdin.readline().split()
    if "insert" in order[0]:
        T.insert(int(order[1]),int(order[2]))
    elif "find" in order[0]:
        print("no") if T.find(int(order[1]))[0] is None else print("yes")
    elif "delete" in order[0]:
        T.delete(int(order[1]))
    else:
        T.print()
