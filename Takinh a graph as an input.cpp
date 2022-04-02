#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, e, p = 0;
    cin >> n >> e;
    int a[100][100];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            a[i][j] = p;
    }
    int n1, n2;
    for(int i=0; i<e; i++)
    {
        cin >> n1 >> n2;
        a[n1][n2] = 1;
        a[n2][n1] = 1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
