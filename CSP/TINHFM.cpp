/*************************
  Author: Defy logic guy
  14:55:11 - 11/01/2025
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
#define NAME "TINHFM"

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= m)
            mp[x]++;
    }

    int ans = 0;
    for (int k = 2; k <= m; k++)
        for (int i = 1; i <= k / 2; i++)
        {
            int j = k - i;
            if (j > m)
                continue;
            if (i == j)
                ans += mp[i] * (mp[i] - 1) / 2;
            else
                ans += mp[i] * mp[j];
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
