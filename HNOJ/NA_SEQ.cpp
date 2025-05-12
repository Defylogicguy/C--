/*************************
 Author: Defy logic guy
22:18:26 - 09/05/2025
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
#define endl '\n'
#define NAME "NA_SEQ"

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pf(n + 1, 0);
    for (int i = 0; i < n; i++)
        pf[i + 1] = pf[i] + a[i];

    sort(all(pf));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = -1, lo = i + 1, ro = n;
        while (lo <= ro)
        {
            int mid = (lo + ro) / 2;
            if (pf[mid] >= pf[i] + l)
            {
                x = mid;
                ro = mid - 1;
            }
            else
                lo = mid + 1;
        }
        int y = -1;
        lo = i + 1, ro = n;
        while (lo <= ro)
        {
            int mid = (lo + ro) / 2;
            if (pf[mid] <= pf[i] + r)
            {
                y = mid;
                lo = mid + 1;
            }
            else
                ro = mid - 1;
        }

        if (x == -1 or y == -1)
            continue;
        ans += y - x + 1;
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
