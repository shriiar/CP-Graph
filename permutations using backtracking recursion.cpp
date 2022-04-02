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

string s;
bool check(int indx, int pos)
{
    for (int i = indx; i < pos; i++)
    {
        if (s[i] == s[pos])
            return 1;
    }
    return 0;
}
void permutation(int indx)
{
    if (indx == s.sz - 1)
    {
        cout << s << endl;
        return;
    }
    for (int i = indx; i < s.sz; i++)
    {
        if (!check(indx, i))
        {
            swap(s[i], s[indx]);
            permutation(indx + 1);
            swap(s[i], s[indx]);
        }
    }
}
signed main()
{
    Fastio;
    cin >> s;
    permutation(0);
}