#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(MAX);
    vector <bool> visited(n, 0);
    for(int i=0; i<e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    int p;
    stack <int> s;
    s.push(1);
    while(!s.empty())
    {
        p = s.top();
        s.pop();
        if(visited[p]==0)
        {
            cout<<p<<" ";
            visited[[] = 1;
        }
        for(int i = )
    }
}

