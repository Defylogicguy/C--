/*************************
  Author: Defy logic guy
  14:09:05 - 15/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_FOUNDSTRING"

void solve()
{
    int n;
    cin >> n;

    map<string, bool> mp;
    while (n--)
    {
        string s;
        cin >> s;
        mp[s] = true;
    }

    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << mp[s] << '\n';
    }
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
