/*************************
  Author: Defy logic guy
  20:22:09 - 15/02/2025
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
#define NAME "C271"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> pfa(n + 1, 0), pfb(m + 1, 0);
    partial_sum(all(a), pfa.begin() + 1);
    partial_sum(all(b), pfb.begin() + 1);

    int ans = 0;
    for (int i = 0, j = m; i <= n; i++)
    {
        if (pfa[i] > k)
            break;
        while (j > 0 && pfa[i] + pfb[j] > k)
            j--;
        ans = max(ans, i + j);
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
