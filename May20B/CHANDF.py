t = int(input())

def reducer(k,l,r):
	kl=[]
	if (k%2==1):
		if (l%2==0):
			i=l+1
			while(i<=r):
				kl.append(i)
				i+=2

		else:
			i=l
			while(i<=r):
				kl.append(i)
				i+=2

	else:
		if (l%2==0):
			i=l
			while(i<=r):
				kl.append(i)
				i+=2

		else:
			i=l+1
			while(i<=r):
				kl.append(i)
				i+=2

	return kl

for i in range(t):
	x,y,l,r = map(int,input().split())
	xl=reducer(x,l,r)
	yl=reducer(y,l,r)

	print(xl)
	print(yl)


	maxx=xl[0]
	maxy=yl[0]

	

	if (len(xl)>len(yl)):
		for i in yl:
			if i in xl:
				print(i)
				break
			else:
				continue

	else:
		for i in xl:
			if i in yl:
				print(i)
				break
			else:
				continue

