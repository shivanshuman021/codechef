# cook your dish here
t = int(input())

for te in range(t):
    n = int(input())
    l = []
    for i in range(n):
        s = str(input())
        l.append(s)
        
    q = int(input())
    
    for i in range(q):
        k = str(input())
        if (k[0]=="1"):
            x = int(k[2])
            h = l[x-1]
            h = h + k[-1]
            l.append(h)
            
        elif (k[0]=="2"):
            print(l.index(min(l)))
            
        elif (k[0]=="3"):
            print(l.index(max(l)))
            
