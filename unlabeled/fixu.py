t = int(input())

for i in range(t):
    n,m = map(int,input().split())
    g= []
    for i in range(n):
        s = str(input())
        g.append(s)

    c = 0
    for i in range(n-1):
        if g[i][-1]=="R":
            c+=1
        
    for i in g[-1]:
        if i=="D":
            c+=1

    print(c)