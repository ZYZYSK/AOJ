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
    def find(self,value):
        p=self.root
        while not p is None:
            if value==p.value:
                return True
            elif value<p.value:
                p=p.left
            else:
                p=p.right
        return False
    def delete(self,value):
        existFlg=False
        p=self.root;q=None
        while not p is None:
            if value==p.value:
                existFlg=True
                break
            elif value<p.value:
                q=p
                p=p.left
            else:
                q=p
                p=p.right
        if not existFlg:return
        #削除するノードが葉の場合
        if p.left is None and p.right is None:
            #親ノードが存在する場合
            if not q is None:
                if q.left==p:
                    q.left=None
                else:
                    q.right=None
            #親ノードが存在しない場合(削除するノードがルート)
            else:
                self.root=None
        #削除するノードが左子だけを持つ場合
        elif p.right is None:
            if q is None:
                self.root=p.left
            elif q.left==p:
                q.left=p.left
            elif q.right==p:
                q.right=p.left
        #削除するノードが右子だけを持つ場合
        elif p.left is None:
            if q is None:
                self.root=p.right
            elif q.left==p:
                q.left=p.right
            elif q.right==p:
                q.right=p.right
        #削除するノードが2つの子を持つ場合
        else:
            #右子の最小ノードを取得
            rp=p.right;rq=p
            while not rp.left is None:
                rq=rp
                rp=rp.left
            #削除するノードと右子の最小ノードの値を入れ替えることで，削除するノードは保持し，代わりに右子の最小ノードを削除する
            p.value=rp.value
            #右子の最小ノードを削除
            if rq.left==rp:
                rq.left=None
            elif rq.right==rp:
                rq.right=None

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
    if "insert" in order:
        T.insert(int(order[1]))
    elif "find" in order:
        print("yes") if T.find(int(order[1])) else print("no")
    elif "delete" in order:
        T.delete(int(order[1]))
    else:
        T.print()
