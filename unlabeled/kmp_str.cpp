#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;cin>>t;
	while (t--)
	{
        string s,p;
        cin>>s;
        cin>>p;
        map <int,int> m;
        
        for (int i=0;i<s.length();++i)
        {
            m[(int(s[i]))]++;
        }

        map <int,int>::iterator it;
        /*for (it = m.begin();it!=m.end();++it)
        {
            cout<<char(it->first)<<" "<<it->second<<"\n";
        }*/

        for (int i=0;i<p.length();++i)
        {
            m[int(p[i])]--;
        }
        /*cout<<"\n";
        for (it = m.begin();it!=m.end();++it)
        {
            cout<<char(it->first)<<" "<<it->second<<"\n";
        }*/
        vector <int> l,g;
        for (it = m.begin();it!=m.end();++it)
        {
            if (it->second > 0)
            {
                if (it->first <= int(p[0]))
                {
                    for (int j=0;j<it->second;++j)
                        l.push_back(it->first);
                }
                else 
                {
                    for (int j=0;j<it->second;++j)
                        g.push_back(it->first);
                }
            }
        }

        /*for (int i=0;i<l.size();++i) cout<<l[i]<<" ";
        cout<<"\n";

        for (int i=0;i<g.size();++i) cout<<g[i]<<" ";
        cout<<"\n";*/

        string fin="";
        for (int i=0;i<l.size();++i) fin+=char(l[i]);
        //cout<<fin<<"\n";
        fin+=p;
        //cout<<fin<<"\n";
        for (int i=0;i<g.size();++i) fin+=char(g[i]);
        cout<<fin<<"\n";
	}

	return 0;
}