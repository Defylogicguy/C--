/*************************
  Author: Defy logic guy
  19:53:14 - 19/07/2025
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
#define NAME "VNOJ-BEDAO_G10_PERFECT"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<pair<int, int>>> st(n + 1, vector<pair<int, int>>(20, {0, 0}));
    for (int i = 1; i <= n; i++)
        st[i][0] = make_pair(a[i], a[i]);
    for (int j = 1; j < 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = {
                min(st[i][j - 1].first, st[i + (1 << (j - 1))][j - 1].first),
                max(st[i][j - 1].second, st[i + (1 << (j - 1))][j - 1].second)};
    vector<int> lg(n + 1, 0);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    auto get = [&](int l, int r)
    {
        int t = lg[r - l + 1];
        return make_pair(
            min(st[l][t].first, st[r - (1 << t) + 1][t].first),
            max(st[l][t].second, st[r - (1 << t) + 1][t].second));
    };
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        auto [mn, mx] = get(l, r);
        cout << ((mx - mn + 1) == (r - l + 1) ? "YES\n" : "NO\n");
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
