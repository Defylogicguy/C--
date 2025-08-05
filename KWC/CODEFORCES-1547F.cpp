/*************************
  Author: Defy logic guy
  20:41:31 - 05/08/2025
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
#define NAME "CODEFORCES-1547F"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * (n + 1));
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i];
    vector<vector<int>> st(2 * (n + 1), vector<int>(20, 0));
    for (int i = 1; i <= 2 * n; i++)
        st[i][0] = a[i];
    for (int i = 1; i < 20; i++)
        for (int j = 1; j + (1 << i) - 1 <= 2 * n; j++)
            st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    vector<int> lg(2 * n + 1, 0);
    for (int i = 2; i <= 2 * n; i++)
        lg[i] = lg[i / 2] + 1;
    auto get = [&](int l, int r)
    {
        int k = lg[r - l + 1];
        return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
    };
    auto f = [&](int mid) -> bool
    {
        for (int i = 2; i <= n; i++)
            if (get(i, i + mid - 1) != get(i - 1, i + mid - 2))
                return false;
        return true;
    };
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (f(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans - 1 << '\n';
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
