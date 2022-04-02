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
bool count(vs& a, char ch)
{
    bool g = 0;
    if(a[0][0] == ch && a[0][1] == ch && a[0][2] == ch) g = 1;
    if(a[1][0] == ch && a[1][1] == ch && a[1][2] == ch) g = 1;
    if(a[2][0] == ch && a[2][1] == ch && a[2][2] == ch) g = 1;

    if(a[0][0] == ch && a[1][0] == ch && a[2][0] == ch) g = 1;
    if(a[0][1] == ch && a[1][1] == ch && a[2][1] == ch) g = 1;
    if(a[0][2] == ch && a[1][2] == ch && a[2][2] == ch) g = 1;

    if(a[0][0] == ch && a[1][1] == ch && a[2][2] == ch) g = 1;
    if(a[0][2] == ch && a[1][1] == ch && a[2][0] == ch) g = 1;
    
    if(g) return 1;
    else return 0; 
    
}
signed main()
{
    Fastio;
    int t;
    cin >> t;
    while(t--)
    {
        int x = 0, o = 0;
        bool xt = 0, ot = 0;
        bool f = 1;
        vs a;
        for0(i, 3)
        {
            string s;
            cin >> s;
            a.pb(s);
            for0(j, s.sz) 
            {
                if(s[j] == 'X') x++;
                if(s[j] == 'O') o++;
            }
        }
        if(o > x) f = 0;
        if(x - o > 1) f = 0;
        xt = count(a, 'X');
        ot = count(a, 'O');

        if(xt && x - o > 1) f = 0;
        if(ot && x - o > 0) f = 0;
        if(xt && ot) f = 0;

        if(f) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}