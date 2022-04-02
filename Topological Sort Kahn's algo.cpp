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
vi lvl, res;
vvi v;
int n, m;
bool kahn()
{
    priority_queue<int,vi,greater<int>> q;
    for1(i, n)
    {
        if(!lvl[i]) q.push(i);
    }
    while(!q.empty())
    {
        int u = q.top();
        res.pb(u);
        q.pop();
        for0(i, v[u].sz)
        {
            lvl[v[u][i]]--;
            if(!lvl[v[u][i]]) q.push(v[u][i]);
        }
    }
    if(res.sz == n) return 1;
    else return 0;
}
signed main()
{
    Fastio;
    cin >> n >> m;
    lvl.resize(10001, 0);
    v.resize(10001);
    for0(i, m)
    {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        lvl[b]++;
    }
    if(kahn())
    {
        for(auto i : res) cout << i << " ";
        cout << endl;
    }
    else cout << "Sandro fails." << endl;
    return 0;
}