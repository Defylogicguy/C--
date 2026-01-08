/*************************
  Author: Defy logic guy
  20:37:37 - 19/07/2025
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
#define NAME "VNOJ-AVLBIT"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<pair<int, int>>> st(n + 1, vector<pair<int, int>>(20, {0, 0}));
    for (int i = 1; i <= n; i++)
        st[i][0] = {a[i], a[i]};
    vector<int> d(n + 1);
    for (int i = 1; i <= n - 1; i++)
        d[i] = abs(a[i] - a[i + 1]);
    vector<vector<int>> st2(n + 1, vector<int>(20, 0));
    for (int i = 1; i <= n - 1; i++)
        st2[i][0] = d[i];
    for (int j = 1; j < 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = {min(st[i][j - 1].first, st[i + (1 << (j - 1))][j - 1].first),
                        max(st[i][j - 1].second, st[i + (1 << (j - 1))][j - 1].second)};
            st2[i][j] = __gcd(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
        }
    vector<int> lg(n + 1, 0);
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    auto get = [&](int l, int r)
    {
        int k = lg[r - l + 1];
        return make_pair(min(st[l][k].first, st[r - (1 << k) + 1][k].first),
                         max(st[l][k].second, st[r - (1 << k) + 1][k].second));
    };
    auto get2 = [&](int l, int r)
    {
        int k = lg[r - l];
        return __gcd(st2[l][k], st2[r - (1 << k) ][k]);
    };
    vector<int> pf(n + 2, 0);
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + (d[i] == 0);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        auto [mn, mx] = get(l, r);
        int g = get2(l, r);
        if ((mx - mn) % (r - l) or (mx == mn) or (pf[r - 1] - pf[l - 1]))
            cout << "NO\n";
        else
            cout << ((mx - mn) / (r - l) == g ? "YES\n" : "NO\n");
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
