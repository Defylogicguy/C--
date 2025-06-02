/*************************
  Author: Defy logic guy
  10:08:45 - 30/05/2025
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
#define NAME "CONTEST10_XOSO"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    const int inf = LLONG_MIN / 4;
    vector<int> prv(k + 1, inf), cur(k + 1, inf);
    vector<map<int, int>> gud(k + 1);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cur.assign(k + 1, inf);

        int extend1 = (i > 0 and a[i] == a[i - 1] + 1 and prv[1] > inf) ? prv[1] + a[i] : a[i];
        cur[1] = max(a[i], extend1);
        ans = max(ans, cur[1]);

        for (int j = 2; j <= k; j++)
        {
            int res = inf;
            if (i > 0 and a[i] == a[i - 1] + 1 and prv[j] > inf)
                res = prv[j] + a[i];
            auto it = gud[j - 1].find(a[i] - 1);
            if (it != gud[j - 1].end())
                res = max(res, it->second + a[i]);
            cur[j] = res;
            ans = max(ans, res);
        }

        for (int j = 1; j <= k; j++)
            if (cur[j] > inf)
            {
                auto &mp = gud[j];
                int &slot = mp[a[i]];
                if (cur[j] > slot)
                    slot = cur[j];
            }

        prv.swap(cur);
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
