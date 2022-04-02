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

#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vpi vector<pair<int, int>>
#define vpl vector<pair<ll, ll>>
#define vplb vector<pair<ll, bool>>
#define vpib vector<pair<int, bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define seti set<int>
#define setl set<ll>
#define mapl map<ll, ll>
#define mapi map<int, int>
#define mults multiset<ll>
#define vs vector<string>

#define for0(i, n) for (ll i = 0; i < n; i++)
#define for1(i, n) for (ll i = 1; i <= n; i++)
#define __lcm(a, b) ((a * b) / __gcd(a, b))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define Fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
signed main()
{
    Fastio;
    int t;
    while (cin >> t)
    {
        if(t == 0) break;
        int n;
        cin >> n;
        vvi v(n + 1);
        vi lvl(n + 1, -1);
        for0(i, n)
        {
            int a, b;
            cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }
        bool f = 1;
        queue<int> q;
        q.push(0);
        lvl[0] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for0(j, v[u].sz)
            {
                if (lvl[v[u][j]] == -1)
                {
                    if (lvl[u] == 1)
                    {
                        lvl[v[u][j]] = 0;
                        q.push(v[u][j]);
                    }
                    else if (lvl[u] == 0)
                    {
                        lvl[v[u][j]] = 1;
                        q.push(v[u][j]);
                    }
                }
                else if (lvl[u] == lvl[v[u][j]])
                {
                    f = 0;
                    break;
                }
            }
        }
        if (f)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
        // cout << f << " " << t << endl;
    }
    return 0;
}