/*************************
  Author: Defy logic guy
  11:09:32 - 22/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "BOKPHANTU"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> p(n - k + 1);
    int cur = 0;
    for (int i = 0; i < k; i++)
        cur += a[i];
    p[0] = cur;

    for (int i = k; i < n; i++)
    {
        cur += -a[i - k] + a[i];
        p[i - k + 1] = cur;
    }

    int m = p.size();
    vector<int> lmx(m), lmn(m), rmx(m), rmn(m);
    lmx[0] = lmn[0] = p[0];
    for (int i = 1; i < m; i++)
    {
        lmx[i] = max(lmx[i - 1], p[i]);
        lmn[i] = min(lmn[i - 1], p[i]);
    }

    rmx[m - 1] = rmn[m - 1] = p[m - 1];
    for (int i = m - 2; i >= 0; i--)
    {
        rmn[i] = min(rmn[i + 1], p[i]);
        rmx[i] = max(rmx[i + 1], p[i]);
    }

    int ans = 0;
    for (int i = 0; i + k < m; i++)
        ans = max({ans, abs(lmx[i] - rmn[i + k]), abs(lmn[i] - rmx[i + k])});
    cout << ans;
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
