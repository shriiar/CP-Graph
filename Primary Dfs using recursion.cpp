#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

vector<vector<int>> v(MAX);
vector <bool> visited(MAX, 0);

void dfs(int source)
{
    visited[source] = 1;
    for(int i=0; i<v[source].size(); i++)
    {
        int y = v[source][i];
        if(visited[y]==0)
            dfs(y);
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    dfs(1);
    for(int i=1; i<=n; i++)
    {
        if(visited[i]==1)
            cout<<i<<" is visited"<<endl;
        else
            cout<<i<<" is not visited"<<endl;
    }
}

