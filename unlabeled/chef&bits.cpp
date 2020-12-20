#include <iostream>
#include <map>
#include <vector>

using namespace std;

void rev(vector<vector<int>> &mat, int x1, int y1, int x2, int y2)
{
    for (int i = x1 - 1; i < x2; ++i)
    {
        for (int j = y1 - 1; j < y2; ++j)
        {
            if (mat[i][j] == 0)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, q;
    cin >> n >> m;
    string s;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            mat[i][j] = s[j];
        }
    }

    int x1, x2, y1, y2;
    cin >> q;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        rev(mat, x1, y1, x2, y2);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << mat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}