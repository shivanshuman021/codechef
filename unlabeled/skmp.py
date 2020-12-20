t = int(input())

def sortstr(my_string): 
    return sorted(sorted(my_string), key=str.upper)

def spl(s):
    j = [ord(char) for char in s]
    return min(j)
    
for i in range(t):
    s = str(input())
    p = str(input())
    d = {}
    for i in s:
        if i in d:
            d[i]+=1
        else:
            d[i]=1

    for i in p:
        d[i]-=1

    l=""
    g=""
    
    #x = spl(p)
    lis = []
    d1 = d.copy()
    for k,v in d.items():
        if (v>0):
            if (ord(k)<ord(p[0])):
                for i in range(v):
                    l+=k
                    d[k]-=1
        
    for k,v in d.items():
        if (v>0):
            for i in range(v):
                g+=k    

    sep = ""
    l = sep.join(sortstr(l))
    g = sep.join(sortstr(g))

    t1 = g + p    
    t2 = p + g
    
    lis.append(min(l+t1,l+t2))
    
    l=""
    g=""
    for k,v in d1.items():
        if (v>0):
            if (ord(k)<=ord(p[0])):
                for i in range(v):
                    l+=k
                    d1[k]-=1
        
    for k,v in d1.items():
        if (v>0):
            for i in range(v):
                g+=k    

    sep = ""
    l = sep.join(sortstr(l))
    g = sep.join(sortstr(g))

    t1 = g + p    
    t2 = p + g
    lis.append(min(l+t1,l+t2))
    
    print(min(lis),end="\n")
    