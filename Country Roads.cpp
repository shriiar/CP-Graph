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
#define vv vector <vector<int>>
#define seti set <int>
#define setl set <ll>
#define mapl map <ll, ll>
#define mapi map <int, int>
#define mults multiset<ll>
#define vs vector<string>

#define for0(i,n) for (ll i=0;i<n;i++)
#define for1(i,n) for (ll i=1;i<=n;i++)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define Fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
signed main()
{
    Fastio;
    int t;
    cin >> t;
    for1(z, t)
    {
        cout << "Case " << z << ":" << endl;
        int n, m;
        cin >> n >> m;
        vector<vector<pair<ll, ll>>> pr(n + 1);
        vl vis(n + 1, -1);
        for0(i, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pr[u].pb({w, v});
            pr[v].pb({w, u});
        }
        priority_queue<pair<ll, ll>, vpl, greater<pair<ll, ll>>> q;
        int h;
        cin >> h;
        q.push({0, h});
        vis[h] = 0;
        while(!q.empty())
        {
            ll pri = q.top().se, pw = q.top().fr;
            q.pop();
            for(int i = 0; i < pr[pri].sz; i++)
            {
                ll chi = pr[pri][i].se, cw = pr[pri][i].fr;
                if(vis[chi] == -1 || max(vis[pri], cw) < vis[chi])
                {
                    vis[chi] = max(vis[pri], cw);
                    q.push({cw, chi});
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == -1) cout << "Impossible" << endl;
            else cout << vis[i] << endl;
        }
    }
    return 0;
}