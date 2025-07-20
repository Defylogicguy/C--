/*************************
  Author: Defy logic guy
  11:47:49 - 20/07/2025
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
#define NAME "2111B"

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> f(n + 1);
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    bool v[151];
    vector<int> s[151];
    for (int h = 1; h <= 150; h++)
    {
        v[h] = true;
        s[h].clear();

        vector<pair<int, int>> st;
        for (int i = n; i >= 1; i--)
        {
            int ht = f[i];
            if (ht > h)
            {
                v[h] = false;
                break;
            }

            int bix = -1;
            int bh = -1;
            for (int j = 0; j < (int)st.size(); j++)
            {
                int hc = st[j].first;
                if (hc + ht <= h)
                {
                    if (hc > bh)
                    {
                        bh = hc;
                        bix = j;
                    }
                }
            }

            if (bix == -1)
                st.push_back({ht, ht});
            else
                st[bix].first += ht;
        }

        if (!v[h])
            s[h].clear();
        else
            for (auto &st : st)
                s[h].push_back(st.second);
    }

    auto can = [&](const vector<int> &b, int w, int l) -> bool
    {
        int o = (int)b.size();
        if (o == 0)
            return true;
        int M = (1 << o);
        int sm[1 << 10], mx[1 << 10];
        for (int msk = 1; msk < M; msk++)
        {
            int s = 0, m = 0;
            for (int bit = 0; bit < o; bit++)
            {
                if (msk & (1 << bit))
                {
                    s += b[bit];
                    m = max(m, b[bit]);
                }
            }
            sm[msk] = s;
            mx[msk] = m;
        }
        int dp[1 << 10];
        int INF = 1e9;
        for (int msk = 0; msk < M; msk++)
            dp[msk] = INF;
        dp[0] = 0;

        for (int msk = 1; msk < M; msk++)
            for (int sub = msk; sub > 0; sub = (sub - 1) & msk)
                if (sm[sub] <= w)
                {
                    int prev = dp[msk ^ sub];
                    if (prev + mx[sub] < dp[msk])
                        dp[msk] = prev + mx[sub];
                }
        return dp[M - 1] <= l;
    };

    string ans(m, '0');
    for (int i = 0; i < m; i++)
    {
        int w, l, h;
        cin >> w >> l >> h;

        bool fits = false;

        int d[3] = {w, l, h};
        for (int j = 0; j < 3 && !fits; j++)
        {
            int ht = d[j];
            if (!v[ht])
                continue;

            int ww = d[(j + 1) % 3];
            int ll = d[(j + 2) % 3];

            const vector<int> &b = s[ht];

            fits = can(b, ww, ll) || can(b, ll, ww);
        }

        ans[i] = (fits ? '1' : '0');
    }

    cout << ans << '\n';
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
