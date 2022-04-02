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
    int n, cs = 1;
    while(cin >> n)
    {
        if(n == 0) break;
        int id = 1;
        vb b(101, 0);
        vvi p(n + 1);
        vi v(101, 0);
        for0(i, n)
        {
            int x, y;
            cin >> x >> y;
            if(!b[x])
            {
                v[x] = id;
                b[x] = 1;
                id++;
            }
            if(!b[y])
            {
                v[y] = id;
                b[y] = 1;
                id++;
            }
            p[v[x]].pb(v[y]);
            p[v[y]].pb(v[x]);
        }
        // for1(i, 100)
        // {
        //     if(v[i] != 0) cout << i << " " << v[i] << endl;
        // }
        // cout << endl;
        vb ff(n + 1, 0);
        for0(i, 101)
        {
            if(b[i]) ff[v[i]] = 1;
        }
        // for1(i, 100) cout << b[i] << " ";
        // cout << endl;
        while(1)
        {
            int x, y, cnt = 0;
            cin >> x >> y;
            if(!x && !y) break;
            queue<int> q;
            q.push(v[x]);
            vi lvl(n + 1, -1);
            lvl[v[x]] = 0;
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                if(lvl[u] == y) continue;
                for0(i, p[u].sz)
                {
                    if(lvl[p[u][i]] == -1)
                    {
                        lvl[p[u][i]] = lvl[u] + 1;
                        q.push(p[u][i]);
                    }
                }
            }
            for1(i, n)
            {
                if(lvl[i] == -1 && ff[i]) 
                {
                    // cout << i << " ";
                    cnt++;
                }
            }
            // cout << endl;
            cout << "Case " << cs << ": " << cnt << " nodes not reachable from node " << x << " with TTL = " << y << endl;
            cs++;
        }
    }
    return 0;
}
