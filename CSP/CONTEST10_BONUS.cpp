/*************************
  Author: Defy logic guy
  22:24:02 - 02/06/2025
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
#define NAME "CONTEST10_BONUS"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    vector<vector<pair<int, int>>> res(n + 1), tmp(n + 1);
    res[0].pb({0, 0});

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            tmp[j].clear();

        for (int j = 0; j <= n; j++)
        {
            auto &v = res[j];
            if (v.empty())
                continue;

            for (auto &k : v)
            {
                if (j <= n)
                    tmp[j].pb({k.first, k.second + a[i]});
                if (j + 1 <= n)
                    tmp[j + 1].pb({k.first, 0});
                if (j >= c[i])
                    tmp[j - c[i]].pb({k.first + k.second + a[i], 0});
            }
        }

        for (int j = 0; j <= n; j++)
        {
            auto &w = tmp[j];
            if (w.empty())
                continue;

            sort(all(w), [](auto &a, auto &b)
                 { return a.first != b.first ? a.first > b.first : a.second > b.second; });

            vector<pair<int, int>> idk;
            int mx = LLONG_MIN;
            for (auto &p : w)
                if (p.second > mx)
                {
                    idk.pb(p);
                    mx = p.second;
                }
            w.swap(idk);
        }

        res.swap(tmp);
    }

    int ans = 0;
    for (int j = 0; j <= n; j++)
        for (auto &p : res[j])
            ans = max(ans, p.first);

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
