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
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool f = 0, g = 1;
        vs v;
        for0(i, n)
        {
            string res;
            f = 0;
            for0(j, n)
            {
                if(j < i)
                {
                    if(v[j][i] == '+') res += '-';
                    else if(v[j][i] == '-') res += '+';
                    else res += '=';
                }
                else if (i == j) res += 'X';
                else
                {
                    if (s[i] == '2')
                    {
                        if (!f && s[j] == '2')
                        {
                            res += '+';
                            f = 1;
                        }
                        else if (s[j] == '1') res += '=';
                        else res += '-';
                    }
                    if (s[i] == '1') res += '=';
                }
            }
            if(s[i] == '2') 
            {
                bool h = 0;
                for0(j, res.sz) if(res[j] == '+')
                {
                    h = 1;
                    break;
                }
                if(!h) 
                {
                    g = 0;
                    break;
                }
            }
            v.pb(res);
        }
        if (!g) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for0(i, v.sz) cout << v[i] << endl;
        }
    }
    return 0;
}