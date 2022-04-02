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
        int n, sum = 0;
        cin >> n;
        vv v(20005);
        vector<char> vc(20005, 'X');
        for0(i, n)
        {
            int a, b;
            cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }
        for1(i, v.sz - 1)
        {
            if (v[i].sz != 0 && vc[i] == 'X')
            {
                int vm = 0, ly = 0;
                queue<int> q;
                q.push(i);
                vc[i] = 'V';
                vm++;
                while (!q.empty())
                {
                    int id = q.front();
                    q.pop();
                    for0(j, v[id].sz)
                    {
                        int val = v[id][j];
                        if (vc[val] == 'X')
                        {
                            q.push(val);
                            if (vc[id] == 'V')
                            {
                                ly++;
                                vc[val] = 'L';
                            }
                            else
                            {
                                vm++;
                                vc[val] = 'V';
                            }
                        }
                    }
                }
                sum += max(vm, ly);
            }
        }
        cout << "Case " << z << ": " << sum << endl;
    }
    return 0;
}