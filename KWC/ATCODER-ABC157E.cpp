/*************************
  Author: Defy logic guy
  21:50:33 - 29/07/2025
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
#define NAME "ATCODER-ABC157E"

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> f[26];
    for (int i = 0; i < 26; i++)
        f[i].assign(n + 2, 0);

    auto add = [&](int idx, int c, int v)
    {
        while (idx <= n)
        {
            f[c][idx] += v;
            idx += idx & -idx;
        }
    };

    auto sum = [&](int idx, int c)
    {
        int res = 0;
        while (idx)
        {
            res += f[c][idx];
            idx -= idx & -idx;
        }
        return res;
    };

    auto get = [&](int l, int r, int c)
    {
        return sum(r, c) - sum(l - 1, c);
    };

    for (int i = 0; i < n; i++)
        add(i + 1, s[i] - 'a', 1);

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            char c;
            cin >> i >> c;
            if (s[i - 1] != c)
            {
                add(i, s[i - 1] - 'a', -1);
                add(i, c - 'a', 1);
                s[i - 1] = c;
            }
        }
        else if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            int res = 0;
            for (int i = 0; i < 26; i++)
                if (get(l, r, i) > 0)
                    res++;
            cout << res << '\n';
        }
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
