/*************************
  Author: Defy logic guy
  23:58:43 - 05/08/2025
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
#define NAME "CODEFORCES-2050F"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << "0\n";
        }
        continue;
    }

    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        d[i] = abs(a[i + 1] - a[i]);
    }

    int m = d.size();
    int max_level = 32 - __builtin_clz(m);
    vector<vector<int>> st(max_level, vector<int>(m));
    st[0] = d;

    for (int j = 1; j < max_level; ++j)
    {
        for (int i = 0; i + (1 << j) <= m; ++i)
        {
            st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << "0\n";
            continue;
        }

        int L = l - 1;
        int R = r - 1;
        int start = L;
        int end = R - 1;
        int len = end - start + 1;

        int k = 31 - __builtin_clz(len);
        int pos2 = end - (1 << k) + 1;
        int g = __gcd(st[k][start], st[k][pos2]);

        cout << (g == 0 ? 0 : g) << "\n";
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
