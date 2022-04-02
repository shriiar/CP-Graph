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
#define pii pair<int, int>
#define pll pair<ll, ll>

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

#define for0(i, n) for (ll i=0;i<n;i++)
#define for1(i, n) for (ll i=1;i<=n;i++)
#define __lcm(a, b) ((a * b) / __gcd(a, b))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define unq(v) (v).erase(unique(all((v))), (v).end())
int dx[]= {-1, 0, 0, 1};
int dy[]= {0, -1, 1, 0};
int dx1[]= {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy1[]= {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dx2[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy2[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

#define Fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
signed main()
{
    Fastio;
    int n, cnt = 0;
    cin >> n;
    vs v, t;
    for0(i, n)
    {
        string s;
        cin >> s;
        v.pb(s);
    }
    for0(i, n)
    {
        string s;
        cin >> s;
        t.pb(s);
    }
    sort(all(v));
    sort(all(t));
    for0(i, t.sz)
    {
        for0(j, v.sz)
        {
            if(v[j].sz == t[i].sz && v[j] == t[i])
            {
                v.erase(v.begin() + j);
                t.erase(t.begin() + i);
                i -= 1;
                break;
            }
        }
    }
    for0(i, t.sz)
    {
        int id, mx = INT_MAX;
        for0(j, v.sz)
        {
            int dis = 0;
            if(v[j].sz == t[i].sz)
            {
                for0(k, v[j].sz)
                {
                    if(v[j][k] != t[i][k]) dis++;
                }
                if(dis <  mx) 
                {
                    mx = dis;
                    id = j;
                }
            }
        }
        v.erase(v.begin() + id);
        cnt += mx;
    }
    cout << cnt << endl;
    return 0;
}