#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void printvec(vector <int> v)
{
    for (int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t,n;cin>>t;
    while(t--)
    {
        cin>>n;
        if (n==1) cout<<1<<endl;
        else if (n==2) cout<<-1<<endl;
        else if (n==3) cout<<"2 3 1"<<endl;
        else if (n==4) cout<<-1<<endl;
        else if (n==5) cout<<"2 3 1 5 4"<<endl;
        else if (n==6) cout<<"2 3 1 5 4 6"<<endl;
        else
        {
            vector<int>v;
            v.push_back(2);
            v.push_back(3);
            v.push_back(1);
            v.push_back(5);
            v.push_back(4);
            v.push_back(6);
            int i=7;int c = 8;
            while(i<=n)
            {
                if (i==c)
                {
                    v.push_back(i+1);
                    ++i;
                }
                else if(i==c+1)
                {
                    v.push_back(i-1);
                    ++i;c*=2;
                }
                else{
                    v.push_back(i);
                    ++i;
                }
            }
            int a = v[v.size()-1],b =v[v.size()-2];
            if (a-b == 2)
            {
                if (a%2==0 && b%2==0)
                    printvec(v);
                else
                    cout<<-1<<endl;
            }
            else
            {
                printvec(v);
            }
        }
    }

    return 0;
}