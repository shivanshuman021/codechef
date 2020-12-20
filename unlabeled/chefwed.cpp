#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printmap(map <int,int> m)
{
    //map <int,int>::iterator it;
    cout<<"map:";
    for (auto it = m.begin();it!=m.end();++it)
    {
        cout<<it->first<<"\n";
    }
 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n,k;cin>>t;
	while(t--)
	{
        cin>>n>>k;
        int a[n];
        for (int j=0;j<n;++j)
            cin>>a[j];
        int cost =0;
        map <int,int> m;
        map <int,int>::iterator it;
        
        for (int i=0;i<n;++i)
        {
            it = m.find(a[i]);
        
            if (it!=m.end())
            {
                cost+=k;
                m.clear();
                m[a[i]]=1;

            }
            else{
                m[a[i]]=1;
            }

        }
        if (m.size()) cost+=k;
        cout<<cost<<"\n";
	}

	return 0;
}