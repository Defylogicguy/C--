/*************************
  Author: Defy logic guy
  09:33:18 - 18/06/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "BIT PROBLEM"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(1 << 20), dp1(1 << 20, 0), dp2(1 << 20, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp1[a[i]]++, dp2[a[i]]++;
    }

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < (1 << 20); j++)
            if (j & (1 << i))
                dp1[j] += dp1[j ^ (1 << i)];
            else
                dp2[j] += dp2[j ^ (1 << i)];
    for (int i = 0; i < n; i++)
        cout << dp1[a[i]] << ' ' << dp2[a[i]]  << ' ' << n - dp1[a[i] ^ ((1 << 20) - 1)] << '\n';
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
