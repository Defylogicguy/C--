/*************************
  Author: Defy logic guy
  08:47:01 - 24/06/2025
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
#define NAME "LASER"

int ref(int d, char m) { return (m == '\\') ? (3 - d) : (d ^ 1); }

void solve()
{
    int n, f, c;
    cin >> n >> f >> c;
    vector<int> row(n), col(n);
    vector<char> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> row[i] >> col[i];

    vector<vector<pair<int, int>>> rl(f + 1), cl(c + 1);
    for (int i = 0; i < n; i++)
        rl[row[i]].pb({col[i], i}), cl[col[i]].pb({row[i], i});
    for (int i = 1; i <= f; i++)
        sort(all(rl[i]));
    for (int i = 1; i <= c; i++)
        sort(all(cl[i]));

    int m = 4 * n;
    vector<int> nxt(m, -1);
    for (int i = 0; i < n; i++)
        for (int d = 0; d < 4; d++)
        {
            int tmp = ref(d, a[i]);
            int j = -1;
            if (tmp == 0)
            {
                auto &lst = cl[col[i]];
                auto it = upper_bound(all(lst), pair<int, int>(row[i], n + 1));
                if (it != lst.end())
                    j = it->second;
            }
            else if (tmp == 1)
            {
                auto &lst = rl[row[i]];
                auto it = upper_bound(all(lst), pair<int, int>(col[i], n + 1));
                if (it != lst.end())
                    j = it->second;
            }
            else if (tmp == 2)
            {
                auto &lst = cl[col[i]];
                auto it = lower_bound(all(lst), pair<int, int>(row[i], -1));
                if (it != lst.begin())
                {
                    it--;
                    j = it->second;
                }
            }
            else
            {
                auto &lst = rl[row[i]];
                auto it = lower_bound(all(lst), pair<int, int>(col[i], -1));
                if (it != lst.begin())
                {
                    it--;
                    j = it->second;
                }
            }
            if (j >= 0)
                nxt[i * 4 + d] = j * 4 + tmp;
        }
    vector<int> dp(m, 0), vis(m, 0);
    vector<char> inf(m, 0);

    for (int i = 0; i < m; i++)
    {
        if (vis[i])
            continue;
        vector<int> t;
        int v = i;
        while (true)
        {
            vis[v] = 1;
            t.pb(v);
            int w = nxt[v];
            if (w < 0)
            {
                int cnt = 0;
                for (int j = t.size() - 1; j >= 0; j--)
                {
                    dp[t[j]] = cnt++;
                    inf[t[j]] = 0;
                }
                break;
            }
            if (vis[w] == 0)
            {
                v = w;
                continue;
            }
            if (vis[w] == 1)
            {
                for (int x : t)
                    inf[x] = 1;
                break;
            }
            if (inf[w])
                for (int x : t)
                    inf[x] = 1;
            else
            {
                int cnt = dp[w] + 1;
                for (int j = t.size() - 1; j >= 0; j--)
                {
                    dp[t[j]] = cnt++;
                    inf[t[j]] = 0;
                }
            }
            break;
        }
        for (int x : t)
            vis[x] = 2;
    }

    int e;
    cin >> e;
    while (e--)
    {
        char ed;
        int er, ec;
        cin >> ed >> er >> ec;
        int d = (ed == 'N') ? 0 : (ed == 'E') ? 1 : (ed == 'S') ? 2 : 3;
        
        int j = -1;
        if (d == 0)
        {
            auto it = upper_bound(all(cl[ec]), pair<int, int>(er, n + 1));
            if (it != cl[ec].end())
                j = it->second;
        }
        else if (d == 1)
        {
            auto it = upper_bound(all(rl[er]), pair<int, int>(ec, n + 1));
            if (it != rl[er].end())
                j = it->second;
        }
        else if (d == 2)
        {
            auto it = lower_bound(all(cl[ec]), pair<int, int>(er, -1));
            if (it != cl[ec].begin())
            {
                it--;
                j = it->second;
            }
        }
        else
        {
            auto it = lower_bound(all(rl[er]), pair<int, int>(ec, -1));
            if (it != rl[er].begin())
            {
                it--;
                j = it->second;
            }
        }
        cout << (j < 0 ? 0 : inf[j * 4 + d] ? -1 : dp[j * 4 + d] + 1) << '\n';
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
