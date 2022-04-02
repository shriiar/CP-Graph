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
signed main()
{
    Fastio;
    int n, m, cs = 1;
    while(cin >> n >> m)
    {
        if(!n && !m) break;
        cout << "Case #" << cs << ":" << endl; 
        int sum = 0, qq;
        vi z;
        z.pb(0);
        for1(i, n)
        {
            int val;
            cin >> val;
            z.pb(val);
            sum += val; 
        }
        vvi x(n + 1), y(n + 1);
        for0(i, m)
        {
            int a, b;
            cin >> a >> b;
            x[a].pb(b);
            y[b].pb(a);
        }
        cin >> qq;
        while(qq--)
        {
            int val;
            cin >> val;
            vb bx(n + 1, 0), by(n + 1, 0);
            queue<int> q;
            int mn = -z[val];
            q.push(val);
            bx[val] = 1;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                mn += z[u];
                for0(i, x[u].sz)
                {
                    if(!bx[x[u][i]])
                    {
                        q.push(x[u][i]);
                        bx[x[u][i]] = 1;
                    }
                }
            }
            q.empty();
            int mx = sum;
            q.push(val);
            by[val] = 1;
            while(!q.empty())
            {
                int u = q.front();
                mx -= z[u];
                q.pop();
                for0(i, y[u].sz)
                {
                    if(!by[y[u][i]])
                    {
                        q.push(y[u][i]);
                        by[y[u][i]] = 1;
                    }
                }
            }
            cout << mx - mn << endl;
        }
        cout << endl;
        cs++;
    }
    return 0;
}