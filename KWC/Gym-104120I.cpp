/*************************
  Author: Defy logic guy
  20:16:55 - 19/07/2025
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
#define NAME "Gym-104120I"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> st(n + 1, vector<int>(20, 0));
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int j = 1; j < 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    vector<int> lg(n + 1, 0);
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    auto get = [&](int l, int r)
    {
        int j = lg[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    };
    int k;
    cin >> k;
    vector<int> q(n + 1, 0), l(n + 1, 0);
    while (k--)
    {
        int m;
        cin >> m;
        vector<int> b(m + 1);
        int ans = 0;
        for (int i = 1; i <= m; i++)
            cin >> b[i], ans += st[b[i]][0];
        vector<int> c(m + 1);
        for (int i = 1; i < m; i++)
            c[i] = get(b[i], b[i + 1]);
        int x;
        x = q[0] = 0;
        for (int i = 1; i < m; i++)
        {
            while (x and c[q[x]] <= c[i])
                x--;
            l[i] = q[x], q[++x] = i;
        }
        q[0] = m, x = 0;
        for (int i = m - 1; i >= 1; i--)
        {
            while (x and c[q[x]] < c[i])
                x--;
            ans += (i - l[i]) * (q[x] - i) * c[i];
            q[++x] = i;
        }
        cout << ans << '\n';
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
