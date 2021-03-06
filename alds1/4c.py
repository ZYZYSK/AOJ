from sys import stdin
n=int(input())
dic=set()
for i in range(n):
    order=stdin.readline()[:-1].split()
    if order[0]=='insert':
        dic.add(order[1])
    if order[0]=='find':
        print('yes') if order[1] in dic else print('no') 
