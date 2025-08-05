/*************************
  Author: Defy logic guy
  21:23:29 - 05/08/2025
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
#define NAME "CODECHEF-SEAD"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> st(n, vector<int>(20, 0));
    for (int i = 0; i < n - 1; i++)
        st[i][0] = a[i + 1] - a[i];
    for (int j = 1; j < 20; j++)
        for (int i = 0; i + (1 << j) < n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    int m;
    cin >> m;
    vector<int> lg(n + 1, 0);
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    auto get = [&](int l, int r)
    {
        int k = lg[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    };
    while (m--)
    {
        int t, d;
        cin >> t >> d;
        int idk = upper_bound(all(a), t) - a.begin() - 1;
        int l = 0, r = idk - 1, ans = idk;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (get(mid, idk - 1) <= d)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        cout << ans + 1 << '\n';
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
