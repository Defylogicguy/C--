/*************************
  Author: Defy logic guy
  20:15:12 - 03/04/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "BOS_SIEUTHI"

void solve()
{
    int m, n, k, s;
    cin >> m >> n >> k >> s;
    vector<vector<int>> a(m + 2, vector<int>(n + 2, 0));
    while (k--)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        a[x][y]++;
        a[x][v + 1]--;
        a[u + 1][y]--;
        a[u + 1][v + 1]++;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == s)
            {
                cnt++;
                a[i][j] = -1;
            }
            else if (a[i][j] == s - 1)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    int ans = LLONG_MIN;
    for (int i = 1; i <= m; i++)
    {
        vector<int> v(n + 1, 0);
        for (int j = i; j <= m; j++)
        {
            for (int l = 1; l <= n; l++)
                v[l] += a[j][l];
            int cur = v[1], mx = v[1];
            for (int l = 2; l <= n; l++)
                cur = max(v[l], cur + v[l]), mx = max(mx, cur);
            ans = max(ans, mx);
        }
    }
    cout << cnt + ans;
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
