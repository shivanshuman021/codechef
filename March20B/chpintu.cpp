#include <map>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>


int main()
{
	int t;std::cin>>t;int n,m,f,p;
	for (int i=0;i<t;i++)
	{
		std::cin>>n>>m;
		int prr[n];int frr[n];
		for (int i=0;i<n;i++) std::cin>>frr[i];
		for (int i=0;i<n;i++) std::cin>>prr[i];

		std::map<int,int> Fn;
		for (int i=0;i<n;i++)
		{
			Fn[frr[i]]++;
		}


		std::map<int,int>::iterator m;

		std::vector <int> vct;
		std::vector<int>::iterator v;
		
		int sum=0,count=0,min=0;
		for (m=Fn.begin();m!=Fn.end();m++)
		{
			sum=0;count=0;
			for (int i=0;count<(m->second);i++)
			{
				if ((m->first)==frr[i]) {count++; sum+=prr[i];}
				else continue;
			}

			vct.push_back(sum);
		}

		min = *min_element(vct.begin(),vct.end());
		std::cout<<min<<std::endl;
	}

	return 0;
}

