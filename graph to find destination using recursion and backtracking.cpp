#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define li long long int
#define ul unsigned long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define sz size()
#define mod 1e9 + 7
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
int n, m;
vector<string> v;
string s;

// // finding paths
// bool findpath(int r, int c)
// {
//     if (r == n - 1 && c == n - 1)
//         return true;
//     if (r == n || c == n)
//         return false;
//     if (v[r][c] == '#')
//         return false;
//     return findpath(r + 1, c) || findpath(r, c + 1);
// }

// count paths
ll countpaths(ll r, ll c)
{
    if (r == n - 1 && c == m - 1)
        return 1;
    if (r == n || c == m)
        return 0;
    if (v[r][c] == '#')
        return 0;
    return countpaths(r + 1, c) + countpaths(r, c + 1);
}

// // print paths
// void printpaths(int r, int c)
// {
//     if (r == n - 1 && c == n - 1)
//     {
//         cout << s << v[r][c] << endl;
//         return;
//     }
//     if (r == n || c == n)
//         return;
//     if (v[r][c] == '#')
//         return;
//     s += v[r][c];
//     printpaths(r + 1, c);
//     printpaths(r, c + 1);
//     s.pop_back();
// }

// // print cordinates
// vpi pr;
// void printcordinate(int r, int c)
// {
//     if (r == n - 1 && c == n - 1)
//     {
//         for (auto it : pr)
//             cout << it.fr << " " << it.se << endl;
//         cout << r << " " << c << endl
//              << endl;
//     }
//     if (r == n || c == n)
//         return;
//     if (v[r][c] == '#')
//         return;
//     pr.pb(mp(r, c));
//     printcordinate(r + 1, c);
//     printcordinate(r, c + 1);
//     pr.pop_back();
// }

// // printng the path using array / vecior of strins
// vector<string> vsr;
// void printvector(int r, int c)
// {
//     if (r == n - 1 && c == n - 1)
//     {
//         vsr[r][c] = '*';
//         for (auto it : vsr)
//             cout << it << endl;
//         cout << endl;
//     }
//     if (r == n || c == n)
//         return;
//     if (v[r][c] == '#')
//         return;
//     vsr[r][c] = '*';
//     printvector(r + 1, c);
//     printvector(r, c + 1);
//     vsr[r][c] = v[r][c];
// }

signed main()
{
    Fastio;
    cin >> n >> m;
    for0(i, n)
    {
        string s;
        cin >> s;
        v.pb(s);
    }
    int ans = countpaths(0, 0);
    ans %= 1000000007;
    cout<<ans<<endl;
    return 0;
}