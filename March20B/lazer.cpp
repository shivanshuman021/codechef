#include <cstdio>

void func(unsigned long long int a[],unsigned int N,unsigned int Q,unsigned int x1,unsigned int x2,unsigned long long int y)
{
	unsigned int cross=0;
			//points in given plane are (i,a[i]);
			//index of y coordinate 

			for (int i=x1;i<x2;i++)
			{
				if (a[i-1]==y) ++cross;
				else if (a[i]==y) ++cross;
				else if (a[i-1]>y && a[i]<y) ++cross;
				else if (a[i-1]<y && a[i]>y) ++cross;
				else continue;
			}

			//std::cout<<cross<<"\n";
			printf("%u\n",cross);
}

int main()
{

	unsigned int T;scanf("%u",&T);
	for (int i=0;i<T;i++)
	{

		//Input
		unsigned int N;
		unsigned int Q;
		scanf("%u %u",&N,&Q);
		unsigned long long int a[N];
		for (int i=0;i<N;i++)
			scanf("%llu",&a[i]);

		unsigned int x1 , x2;unsigned long long int y;
		for (int i=0;i<Q;i++)
		{
			scanf("%u %u %llu",&x1,&x2,&y);
		
			//Output
			func(a,N,Q,x1,x2,y);
			
		}
	}

	return 0;
}