#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> v, vector<bool> &b, int n)
{
    b[n] = 1;
    for (int i = 0; i < v[n].size(); i++)
    {
        int x = v[n][i];
        if (b[x] == 0)
        {
            dfs(v, b, x);
        }
    }
}
signed main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(10000);
    vector<bool> b(10000, 0);
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
    }
    int x;
    cin >> x;
    dfs(v, b, x);
    for(int i = 0; i <= n; i++)
    {
        if(!b[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}