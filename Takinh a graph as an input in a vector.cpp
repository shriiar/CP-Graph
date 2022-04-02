#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(MAX);
    for(int i=0; i<e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" --> ";
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}
