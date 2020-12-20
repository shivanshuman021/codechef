#include <iostream>
#include <map>
#include <climits>
#include <vector>

using namespace std;

void prlongvec(vector <long> &v)
{
    cout<<"vector\n";
    for (long i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

long wedarg(vector <vector <long> > &mat,long beg ,long end,long cost)
{
    
    //end is the inclusive index of last element of array
    if (beg>=end) 
    {
        //cout<<"this returned\n";
        return cost;
    }
    vector <long> v,vindex;long cmin=long_MAX,c2=0;
    for (long i=beg;i<end-1;++i)
    {
        c2 = mat[beg][i]+mat[i+1][end];
        v.push_back(c2);
        vindex.push_back(i);
        if (c2<cmin)
        {
            cmin=c2;
        }
    }

    if (cmin>=cost) 
    {
        //cout<<"returned cost for beg = "<<beg<<" end = "<<end<<"\n";
        return cost;
    }

    vector <long> minvec;
    for (long i=0;i<v.size();++i)
    {
        if (v[i]==cmin)
            minvec.push_back(vindex[i]);
    }

    vector <long> vcost ;
    cmin = cost;
    long x ;
    for (long i=0;i<minvec.size()-1;++i)
    {
        x = wedarg(mat,beg,minvec[i],mat[beg][minvec[i]]);
        x += wedarg(mat,minvec[i]+1,end,mat[minvec[i]+1][end]);
        //cout<<"beg = "<<beg<<" to end = "<<end<<" x is "<<x<<"\n";
        //vcost.push_back(x);
        if (x<cmin)
        {
            cmin = x;
        }        
    }
    //prlongvec(vcost);
    //cout<<"beg = "<<beg<<" end = "<<end<<" cmin is "<<cmin<<"\n";

    return cmin;
}

long main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    long t,n,k;
    cin>>t;
    while(t--)
    {   
        cin>>n>>k;
        long a[n];
        
        for (long i=0;i<n;++i) cin>>a[i];

        map<long,long> m;
        map<long,long>::iterator it;
        if (k==1)
        {
            long cost =0;
            for (long i=0;i<n;++i)
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
        else{
        vector <vector<long> > mat(n,vector <long> (n,0));
        
        mat[0][0]=k;
        m[a[0]]=1;
        for (long j=1;j<n;++j)
            {
                it = m.find(a[j]);
                if (it!=m.end())
                {
                    if (m[a[j]]==1)
                    {
                        m[a[j]]++;
                        mat[0][j]=mat[0][j-1]+2;
                    }
                    else if (m[a[j]]>1)
                    {
                        m[a[j]]++;
                        mat[0][j]=mat[0][j-1]+1;
                    }
                }
                else{
                    m[a[j]]=1;
                    mat[0][j]=mat[0][j-1];
                }
            }

        

        for (long i=1;i<n;++i)
        {
            m.clear();
            for (long j=i;j<n;++j)
            {
                if (i==j) mat[i][j]=k;
                else{
                    it = m.find(a[j]);
                    if (it!=m.end())
                    {
                        if (m[a[j]]==1)
                        {
                            m[a[j]]++;
                            mat[i][j]=mat[i][j-1]+2;
                        }
                        else if (m[a[j]]>1)
                        {
                            m[a[j]]++;
                            mat[i][j]=mat[i][j-1]+1;
                        }
                    }
                    else{
                        m[a[j]]=1;
                        mat[i][j]=mat[i][j-1];
                    }
                }
            }
        }

        
        long cost = wedarg(mat,0,n-1,mat[0][n-1]);

        cout<<cost<<"\n";

        }
    }

    return 0;
}
