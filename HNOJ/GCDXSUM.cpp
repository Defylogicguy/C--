/*************************
  Author: Defy logic guy
  10:25:37 - 30/08/2025
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
#define NAME "GCDXSUM"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int mxa = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mxa = max(mxa, a[i]);
    vector<int> pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + a[i];
    vector<int> spf(mxa + 1);
    for (int i = 2; i <= mxa; i++)
        if (!spf[i])
            for (int j = i; j <= mxa; j += i)
                if (!spf[j])
                    spf[j] = i;
    spf[1] = 1;
    vector<vector<int>> pos(mxa + 1);
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        vector<pair<int, int>> f;
        while (x > 1)
        {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0)
            {
                x /= p;
                cnt++;
            }
            f.emplace_back(p, cnt);
        }
        vector<int> d;
        d.pb(1);
        for (auto it : f)
        {
            int mul = 1;
            int sz = d.size();
            for (int j = 0; j < it.second; j++)
            {
                mul *= it.first;
                for (int u = 0; u < sz; u++)
                    d.pb(d[u] * mul);
            }
        }
        for (int j : d)
            pos[j].pb(i);
    }
    int ans = 0;
    for (int i = 1; i <= mxa; i++)
    {
        auto v = pos[i];
        if (v.size() < k)
            continue;
        int idx = 0;
        while (idx < v.size())
        {
            int st = v[idx];
            int j = idx + 1;
            while (j < v.size() and v[j] == v[j - 1] + 1)
                j++;
            int end = v[j - 1];
            int l = end - st + 1;
            if (l >= k)
            {
                int mn = pf[st - 1];
                int mx = LLONG_MIN;
                for (int u = st + k - 1; u <= end; u++)
                {
                    mx = max(mx, pf[u] - mn);
                    mn = min(mn, pf[u - k + 1]);
                }
                ans = max(ans, i * mx);
            }
            idx = j;
        }
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
