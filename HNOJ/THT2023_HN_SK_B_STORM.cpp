/*************************
  Author: Defy logic guy
  18:33:22 - 20/03/2026
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
#define NAME "THT2023_HN_SK_B_STORM"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    vector<vector<int>> b(2 * n + 1, vector<int>(2 * n + 1, -1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i + j][i - j + n] = a[i][j];
    vector<vector<int>> d(2 * n + 2, vector<int>(2 * n + 2, 0));
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
        {
            if (b[i][j] <= 0)
                continue;
            int x = b[i][j];
            int r1 = max(0ll, i - x);
            int c1 = max(0ll, j - x);
            int r2 = min(2 * n, i + x);
            int c2 = min(2 * n, j + x);
            d[r1][c1]++;
            d[r1][c2 + 1]--;
            d[r2 + 1][c1]--;
            d[r2 + 1][c2 + 1]++;
        }
    for (int i = 1; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
            d[i][j] += d[i - 1][j];
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 1; j <= 2 * n; j++)
            d[i][j] += d[i][j - 1];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cnt += (d[i + j][i - j + n] > 0);
    cout << n * n - cnt;
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
