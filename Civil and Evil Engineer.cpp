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
#define vv vector<vector<int>>
#define seti set<int>
#define setl set<ll>
#define mapl map<ll, ll>
#define mapi map<int, int>
#define mults multiset<ll>
#define vs vector<string>

#define for0(i, n) for (ll i = 0; i < n; i++)
#define for1(i, n) for (ll i = 1; i <= n; i++)

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
    cin >> t;
    for1(z, t)
    {
        cout << "Case " << z << ": ";
        ll n, mx = 0, mn = 0;
        cin >> n;
        vector<vector<pair<ll, ll>>> p(n + 1);
        priority_queue<pair<ll, ll>, vpl, greater<pair<ll, ll>>> q;
        priority_queue<pair<ll, ll>> qq;
        vi v(n + 1, -1);
        while (1)
        {
            ll a, b, w;
            cin >> a >> b >> w;
            if (a == 0 && b == 0 && w == 0) break;
            p[a].pb({w, b});
            p[b].pb({w, a});
        }
        q.push({0, 0});
        while (!q.empty())
        {
            ll pid = q.top().se, val = q.top().fr;
            q.pop();
            if (v[pid] == 1) continue;
            mn += val;
            v[pid] = 1;
            for0(i, p[pid].sz)
            {
                if (v[p[pid][i].se] == 1) continue;
                q.push({p[pid][i].fr, p[pid][i].se});
            }
        }
        vi t(n + 1, -1);
        qq.push({0, 0});
        while (!qq.empty())
        {
            ll pid = qq.top().se, val = qq.top().fr;
            qq.pop();
            if (t[pid] == 1) continue;
            mx += val;
            t[pid] = 1;
            for0(i, p[pid].sz)
            {
                if (t[p[pid][i].se] == 1) continue;
                qq.push({p[pid][i].fr, p[pid][i].se});
            }
        }
        cout << mn << " " << mx << endl;
        if ((mx + mn) % 2 == 0) cout << (mx + mn) / 2 << endl;
        else cout << mx + mn << "/" << 2 << endl;
    }
    return 0;
}