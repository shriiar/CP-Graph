#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define li long long int
#define ul unsigned long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define sz size()
#define mod 1000000007
#define fr first
#define se second

#define vi vector <int>
#define vb vector <bool>
#define vl vector <ll>
#define vpi vector <pair<int, int>>
#define vpl vector <pair<ll, ll>>
#define vplb vector <pair<ll, bool>>
#define vpib vector <pair<int, bool>>
#define vvi vector <vector<int>>
#define vvl vector <vector<ll>>
#define seti set <int>
#define setl set <ll>
#define mapl map <ll, ll>
#define mapi map <int, int>
#define mults multiset<ll>
#define vs vector<string>

#define for0(i,n) for (ll i=0;i<n;i++)
#define for1(i,n) for (ll i=1;i<=n;i++)
#define __lcm(a, b) ((a * b) / __gcd(a, b))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define Fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n, m, d;
vi lvl, par;
vvi path;
void bfs(int i)
{
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int indx = q.front();
        q.pop();
        for0(j, path[indx].sz)
        {
            if(lvl[path[indx][j]] == 0)
            {
                lvl[path[indx][j]] = lvl[indx] + 1;
                par[path[indx][j]] = indx;
                q.push(path[indx][j]);
            }
        }
    }
}
signed main()
{
    Fastio;
    cin >> n >> m >> d;
    path.resize(n + 1);
    lvl.resize(n + 1, 0);
    par.resize(n + 1, -1);
    for0(i, m)
    {
        int u, v;
        cin >> u >> v;
        path[u].pb(v);
        path[v].pb(u);
    }
    bfs(1);
    int dis = par[d];
    cout << lvl[d] << " "<< d << " " << par[d] << " ";
    while(1)
    {
        if(dis == 1) break;
        dis = par[dis];
        cout << dis << " ";
    }
    cout << endl;
    return 0;
}