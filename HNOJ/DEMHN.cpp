/*************************
  Author: Defy logic guy
  08:43:27 - 04/01/2025
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
#define NAME "DEMHN"

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int ans = 0;
    k %= MOD;
    int sum = k * (k - 1) / 2;
    int cnt = count(all(s), 'N');
    int cur = 0;
    int idk = ((sum % MOD) * cnt) % MOD;
    for (int i = s.size() - 1; i >= 0; i--)
        if (s[i] == 'N')
            cur = (cur + k) % MOD;
        else
        {
            ans += cur + idk;
            ans %= MOD;
        }
    cout << ans << endl;
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
