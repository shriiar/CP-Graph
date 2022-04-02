#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define li long long int
#define ul unsigned long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define sz size()
#define mod = 1e9 + 7
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
    while (t--)
    {
        ll n, res, mn = 5e18, tm = 0;
        cin >> n;
        res = n;

        tm += (n / 10) * 25;
        n -= (n / 10) * 10;
        if (n > 8)
        {
            tm += 25;
            n -= 10;
        }
        if (n > 7 && n <= 8)
        {
            tm += 20;
            n -= 8;
        }
        if (n > 0 && n <= 6)
        {
            tm += 15;
            n -= 6;
        }
        mn = min(mn, tm);

        tm = 0;
        n = res;
        tm += (n / 8) * 20;
        n -= (n / 8) * 8;
        if (n == 7)
        {
            tm += 20;
            n -= 8;
        }
        if (n > 0 && n <= 6)
        {
            tm += 15;
            n -= 6;
        }
        mn = min(mn, tm);

        tm = 0;
        n = res;
        tm += (n / 6) * 15;
        n -= (n / 6) * 6;
        if (n > 0 && n < 6)
        {
            tm += 15;
            n -= 6;
        }
        mn = min(mn, tm);
        if (res == 7)
            mn = 20;
        cout << mn << endl;
    }
    return 0;
}