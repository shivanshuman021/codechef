def motion(x,y,a):
	if a=="L":
		x-=1
	elif a=="R":
		x+=1
	elif a=="U":
		y+=1
	elif a=="D":
		y-=1


def validate(s,j):
	if (s[j]=="L" && (s[j-1]=="L" || s[j-1]=="R")):
		return -1
	elif (s[j]=="R" && (s[j-1]=="L" || s[j-1]=="R")):
		return -1
	elif (s[j]=="U" && (s[j-1]=="U"||s[j-1]=="D")):
		return -1
	elif (s[j]=="D" && (s[j-1]=="U"||s[j-1]=="D")):
		return -1
	else:
		return 1



if __name__ == "__main__":
	T = int(input())
	x=0
	y=0
	s="string"
	for i in range(T):
		s = str(input())
		x=0
		y=0
		motion(x,y,s[0])
		j=1
		while (j<len(s)):
			result = validate(s,j)
			if result==-1:
				j++

			else:
				motion(x,y,s[j])

		print(x,y,end=" ")

