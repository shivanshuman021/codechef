#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string s;
        cin >> s;
        string g = s.substr(0, n);
        string k;
        bitset<50> fin(g);
        for (int i = 1; i < n; ++i)
        {
            k = s.substr(i, n);
            bitset<50> temp(k);
            fin = fin & temp;
        }
        //cout << fin << "\n";
        string ans = fin.to_string();
        //for (int i = 50 - n; i < 50; ++i)
        //{
        //   cout << "i = " << i << "val " << fin[i] << " ";
        //}
        cout << ans.substr(50 - n, n);
        cout << "\n";
    }

    return 0;
}