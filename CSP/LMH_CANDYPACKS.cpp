/*************************
  Author: Defy logic guy
  14:22:03 - 27/06/2025
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
#define NAME "LMH_CANDYPACKS"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    vector<int> pf(n + 1, 0);
    partial_sum(all(a), pf.begin() + 1);
    int ans = LLONG_MAX;
    for (int i = 0; i <= n - m; i++)
    {
        int l = i, r = i + m;
        int sum = pf[r] - pf[l];
        for (int j : {sum / m, (sum + m - 1) / m})
        {
            int lo = l, hi = r - 1, res = r;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (a[mid] >= j)
                {           
                    res = mid;
                    hi = mid    - 1;
                }
                else
                    lo = mid + 1;
            }
            ans = min(ans, max(j * (res - l) - pf[res] + pf[l], pf[r] - pf[res] - j * (r - res)));
        }
    }
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
