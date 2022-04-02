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
#define ppl pair<ll, ll>

#define for0(i,n) for (ll i=0;i<n;i++)
#define for1(i,n) for (ll i=1;i<=n;i++)
#define __lcm(a, b) ((a * b) / __gcd(a, b))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define Fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
signed main()
{
    Fastio;
    ll w, x, y, z, n;
    cin >> w >> x >> y >> z >> n;
    map<ppl, ll> mapp;
    mapp[{w, x}] = 1;
    for0(i, n)
    {
        ll r, a, b;
        cin >> r >> a >> b;
        for(int j = a; j <= b; j++) mapp[{r, j}] = 1;
    }
    queue<ppl> q;
    q.push({w, x});
    while(!q.empty())
    {
        ppl u = q.front();
        q.pop();
        if(mapp[{u.fr - 1, u.se}] == 1)
        {
            q.push({u.fr - 1, u.se});
            mapp[{u.fr - 1, u.se}] = mapp[{u.fr, u.se}] + 1;
        }
        if(mapp[{u.fr - 1, u.se - 1}] == 1)
        {
            q.push({u.fr - 1, u.se - 1});
            mapp[{u.fr - 1, u.se - 1}] = mapp[{u.fr, u.se}] + 1;
        }
        if(mapp[{u.fr, u.se - 1}] == 1)
        {
            q.push({u.fr, u.se - 1});
            mapp[{u.fr, u.se - 1}] = mapp[{u.fr, u.se}] + 1;
        }
        if(mapp[{u.fr - 1, u.se + 1}] == 1)
        {
            q.push({u.fr - 1, u.se + 1});
            mapp[{u.fr - 1, u.se + 1}] = mapp[{u.fr, u.se}] + 1;
        }
        if(mapp[{u.fr, u.se + 1}] == 1)
        {
            q.push({u.fr, u.se + 1});
            mapp[{u.fr, u.se + 1}] = mapp[{u.fr, u.se}] + 1;
        }
        if(mapp[{u.fr + 1, u.se + 1}] == 1)
        {
            q.push({u.fr + 1, u.se + 1});
            mapp[{u.fr + 1, u.se + 1}] = mapp[{u.fr, u.se}] + 1;
        }
        if(mapp[{u.fr + 1, u.se}] == 1)
        {
            q.push({u.fr + 1, u.se});
            mapp[{u.fr + 1, u.se}] = mapp[{u.fr, u.se}] + 1;
        }
        if(mapp[{u.fr + 1, u.se - 1}] == 1)
        {
            q.push({u.fr + 1, u.se - 1});
            mapp[{u.fr + 1, u.se - 1}] = mapp[{u.fr, u.se}] + 1;
        }
    }
    if(mapp[{y, z}] > 1) cout << mapp[{y, z}] - 1 << endl;
    else if(w == y && x == z) cout << 1 << endl;
    else cout << -1 << endl;
    return 0;
}