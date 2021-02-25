from collections import deque
class queue:
    def __init__(self) -> None:
        self.queue=deque()
    def push(self,x):
        self.queue.append(x)
    def pop(self):
        return self.queue.popleft()
    def empty(self):
        return True if len(self.queue)==0 else False
n,q=[int(i) for i in input().split()]
que=queue()
cnt=0
for i in range(n):
    t=input().split()
    que.push([t[0],int(t[1])]) 
while not que.empty():
    t=que.pop()
    t[1]-=q
    if t[1]>0:
        cnt+=q
        que.push(t)
    else:
        cnt+=(t[1]+q)
        print(f'{t[0]} {cnt}')