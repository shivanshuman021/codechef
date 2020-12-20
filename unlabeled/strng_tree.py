t = int(input())

def eat(joint

for te in range(t):
    n = int(input())
    joint = [[] for i in range(n)]
    
    for i in range(n-1):
    	u,v = map(int,input().split())
    	joint[u-1].append(v-1)
    	joint[v-1].append(u-1)
    	
    p = list(map(int,input().split()))
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    
    

    

    		
