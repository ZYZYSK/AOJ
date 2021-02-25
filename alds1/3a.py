class stack:
    def __init__(self) -> None:
        self.stack=[]
    def push(self,a):
        self.stack.append(a)
    def pop(self):
        return self.stack.pop()
formula=[i for i in input().split()]
stk=stack()
for i in formula:
    if i=='+':
        stk.push(stk.pop()+stk.pop())
    elif i=='-':
        stk.push(-1*(stk.pop()-stk.pop()))
    elif i=='*':
        stk.push(stk.pop()*stk.pop())
    else:
        stk.push(int(i))
print(stk.pop())
