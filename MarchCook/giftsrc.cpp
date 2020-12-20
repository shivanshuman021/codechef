#include <iostream>
#include <string>
using namespace std;

void motion(int x,int y,char a)
{
	
	if (a== "L") x--;
	else if (a == "R") x++;
	else if (a=="U") y++;
	else if (a=="D") y--;
}

int validate(string s,int j)
{
	if (s[j]=="L" && ((s[j-1]=="L") || (s[j-1]=="R"))) return -1;
	else if (s[j]=="R" && ((s[j-1]=="L") || (s[j-1]=="R"))) return -1;
	else if (s[j]=="U" && ((s[j-1]=="U")||(s[j-1]=="D"))) return -1;
	else if (s[j]=="D" && ((s[j-1]=="U")||(s[j-1]=="D"))) return -1;
	else return 1;
}


int main()
{
	int T;string s;int x=0,y=0;
	for (int i=0;i<T;i++)
	{

		cin>>s;x=0;y=0;int result;
		char a=s[0];
		motion(x,y,a);
		int j =1;
		while (j<s.length())
		{
			result = validate(s,j);
			if (result==-1) j++;
			else 
			{
				a = s[j];
				motion(x,y,a);
			}
		}

		cout<<x<<" "<<y;
	}

	return 0;
}
