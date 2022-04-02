#include <bits/stdc++.h>
using namespace std;
vector<int> s1;
vector<int> s2;
void dfs(vector<vector<int>> v, vector<bool> &b, int n)
{
    b[n] = 1;
    for (int i = 0; i < v[n].size(); i++)
    {
        int x = v[n][i];
        if (b[x] == 0)
        {
            dfs(v, b, x);
            s1.push_back(x);
        }
    }
}
void dfs1(vector<vector<int>> v, vector<bool> &d, int n)
{
    d[n] = 1;
    for (int i = 0; i < v[n].size(); i++)
    {
        int x = v[n][i];
        if (d[x] == 0)
        {
            dfs1(v, d, x);
            s2.push_back(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(10000);
    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    int x, y;
    cin >> x >> y;
    vector<bool> b(10000, 0), d(10000, 0);
    dfs(v, b, x);
    dfs1(v, d, y);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    bool f = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        bool g = binary_search(s2.begin(), s2.end(), s1[i]);
        if (g)
        {
            cout << "Common adjacent node of " << x << " and " << y << " is " << s1[i] << endl;
            return 0;
        }
    }
    cout << "There isnt a common adjacent node of " << x << " and " << y << endl;
    return 0;
}
