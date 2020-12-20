import operator as op
from functools import reduce

te = int(input())


def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return int(numer / denom)

def nemptydict(d):
    for k,v in d.items():
        if v>0:
            return 1
        else:
            continue
    return 0

def power(x,y):
    M =1000000007
    res = 1
    x = x%M
    if (x==0):
        return 0

    while(y>0):
        if (y%2==1):
            res = (res*x)%M
        
        y = int(y/2)
        x = (x*x)%M

    return res

def maxel(d):
    key = max(d,key=d.get)
    l = []
    for k,v in d.items():
        if (v==d[key]):
            l.append(k)
    
    return min(l)


for t in range(te):
    n = int(input())    
    a = list(map(int,input().split()))
    M = 1000000007
    d= {}

    for ele in a:
        if ele in d:
            d[ele]+=1
        else:
            d[ele]=1;

    fin = {}
    ans = 1
    dcopy = d.copy()
    while(nemptydict(d)):
        ans = 1
        key = maxel(d)

        #print("d is ")
        #print(d)
        #print("fin is ")
        #print(fin)
        
        for k,v in d.items():
            if (k==key):
                continue
            else:
                ans = ans*(power(2,v))%M
                #print("k = "+str(k)+" v = "+str(v)+" "+str(ans))
        ans = (ans*(ncr(dcopy[key],d[key])%M))%M
        if key in fin:
            fin[key]+= ans
        else: 
            fin[key]=ans
        #print("fin is ")
        #print(fin)

        d[key]-=1


    for i in range(1,n+1):
        if i in fin:
            print(fin[i],end=" ")
        else:
            print(0,end=" ")
    print()

    
        
