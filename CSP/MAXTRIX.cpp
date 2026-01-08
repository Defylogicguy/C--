/*************************
  Author: Defy logic guy
  07:43:44 - 22/02/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "MAXTRIX"

const int base = 997;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> Pow(m + 1, 1);
    for (int i = 1; i <= m; i++)
        Pow[i] = (Pow[i - 1] * base) % MOD;

    vector<vector<int>> hash(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            hash[i][j + 1] = (hash[i][j] * base + a[i][j] - '0') % MOD;

    auto get = [&](int idx, int l, int r) -> int
    {
        int len = r - l + 1;
        int res = (hash[idx][r] - (hash[idx][l - 1] * Pow[len]) % MOD + MOD) % MOD;
        return res;
    };

    int ans = 0;

    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++)
        {
            vector<int> tmp(n);
            for (int r = 0; r < n; r++)
                tmp[r] = get(r, i, j);

            vector<int> d1(n, 0);
            int l = 0, r = -1;
            for (int u = 0; u < n; u++)
            {
                int k = 1;
                if (u <= r)
                    k = min(d1[l + r - u], r - u + 1);
                while (u - k >= 0 && u + k < n && tmp[u - k] == tmp[u + k])
                    k++;
                d1[u] = k;
                k--;
                if (u + k > r)
                {
                    l = u - k;
                    r = u + k;
                }
            }

            vector<int> d2(n, 0);
            l = 0, r = -1;
            for (int u = 0; u < n; u++)
            {
                int k = 0;
                if (u <= r)
                    k = min(d2[l + r - u + 1], r - u + 1);
                while (u - k - 1 >= 0 && u + k < n && tmp[u - k - 1] == tmp[u + k])
                    k++;
                d2[u] = k;
                if (u + k - 1 > r)
                {
                    l = u - k;
                    r = u + k - 1;
                }
            }

            int cnt = 0;
            for (int u = 0; u < n; u++)
                cnt += d1[u] + d2[u];
            cnt -= n;
            ans += cnt;
        }

    cout << ans << endl;
}

signed main()
{
    if (fopen(NAME ".INP", "k"))
    {
        freopen(NAME ".INP", "k", stdin);
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
