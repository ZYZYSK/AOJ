def solver(string):
    ans=0
    ground=[]
    water=[]
    for i in range(len(string)):
        if string[i]=='\\':
            ground.append(i)
        elif string[i]=='/':
            if len(ground)==0:continue
            p=ground.pop()
            ans+=(i-p)
            q=0
            while len(water)>0 and water[len(water)-1][0]>p:
                q+=water.pop()[1]
            water.append([p,q+(i-p)])
    print(ans)
    print(len(water),end='')
    for i in water:
        print(f' {i[1]}',end='')
    print()     
string=input()
solver(string)