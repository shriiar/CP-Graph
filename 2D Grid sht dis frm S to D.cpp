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
#define pii pair<int, int>

#define for0(i,n) for (ll i=0;i<n;i++)
#define for1(i,n) for (ll i=1;i<=n;i++)
#define __lcm(a, b) ((a * b) / __gcd(a, b))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define Fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n, m;
vvi lvl;
vs v;
pii s, d;
void bfs(int i, int j)
{
    queue<pii> q;
    q.push({i, j});
    while(!q.empty())
    {
        pii u = {q.front().fr, q.front().se};
        q.pop();
        if(u.fr + 1 < n && v[u.fr + 1][u.se] != '#' && lvl[u.fr + 1][u.se] == 0)
        {
            lvl[u.fr + 1][u.se] = lvl[u.fr][u.se] + 1;
            q.push({u.fr + 1, u.se});
        }
        if(u.fr - 1 >= 0 && v[u.fr - 1][u.se] != '#' && lvl[u.fr - 1][u.se] == 0)
        {
            lvl[u.fr - 1][u.se] = lvl[u.fr][u.se] + 1;
            q.push({u.fr - 1, u.se});
        }
        if(u.se + 1 < m && v[u.fr][u.se + 1] != '#' && lvl[u.fr][u.se + 1] == 0)
        {
            lvl[u.fr][u.se + 1] = lvl[u.fr][u.se] + 1;
            q.push({u.fr, u.se + 1});
        }
        if(u.se - 1 >= 0 && v[u.fr][u.se - 1] != '#' && lvl[u.fr][u.se - 1] == 0)
        {
            lvl[u.fr][u.se - 1] = lvl[u.fr][u.se] + 1;
            q.push({u.fr, u.se - 1});
        }
    }
}
signed main()
{
    Fastio;
    cin >> n >> m;
    lvl.resize(n, vi(m, 0));
    for0(i, n)
    {
        string st;
        cin >> st;
        v.pb(st);
        for0(j, m)
        {
            if(st[j] == 'S') s = {i, j};
            else if(st[j] == 'D') d = {i, j};
        }
    }
    bfs(s.fr, s.se);
    cout << lvl[d.fr][d.se] << endl;
    return 0;
}