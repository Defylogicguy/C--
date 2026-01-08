/*************************
  Author: Defy logic guy
  14:23:16 - 15/03/2025
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
#define NAME "CSPHN_SM"

void solve()
{
    string s, t;
    cin >> s >> t;

    int hashs = 0;
    for (char c : s)
        hashs = (hashs * 31 + c) % MOD;
    vector<int> hasht(t.size() + 1, 0), Pow(t.size() + 1, 1);
    for (int i = 1; i <= t.size(); i++)
    {
        hasht[i] = (hasht[i - 1] * 31 + t[i - 1]) % MOD;
        Pow[i] = (Pow[i - 1] * 31) % MOD;
    }

    vector<int> ans;
    for (int i = s.size(); i <= t.size(); i++)
    {
        int cur = (hasht[i] - (hasht[i - s.size()] * Pow[s.size()]) % MOD + MOD) % MOD;
        if (cur == hashs)
            ans.pb(i - s.size());
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
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