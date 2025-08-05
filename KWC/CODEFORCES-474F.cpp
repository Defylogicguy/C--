/*************************
  Author: Defy logic guy
  00:00:06 - 06/08/2025
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
#define NAME "CODEFORCES-474F"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
        mp[a[i]].push_back(i);
    vector<vector<int>> st(21, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        st[0][i] = a[i];
    vector<int> lg(n + 2);
    lg[1] = 0;
    for (int i = 2; i <= n + 1; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i < 21; i++)
        for (int j = 1; j + (1 << i) <= n + 1; j++)
            st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1ll << (i - 1))]);
    auto get = [&](int l, int r) -> int
    {
        int len = r - l + 1;
        int k = lg[len];
        return __gcd(st[k][l], st[k][r - (1ll << k) + 1]);
    };
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int i = get(l, r);
        cout << r - l + 1 - (upper_bound(mp[i].begin(), mp[i].end(), r) - lower_bound(mp[i].begin(), mp[i].end(), l)) << '\n';
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
