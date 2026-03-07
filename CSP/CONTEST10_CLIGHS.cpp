/*************************
  Author: Defy logic guy
  15:00:12 - 07/03/2026
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
#define NAME "CLIGHS"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            a[i][j] ^= x;
        }
    int ans = LLONG_MAX;
    int M = (1 << n);
    for (int m = 0; m < M; m++)
    {
        int cnt = 0;
        vector<vector<int>> c(n, vector<int>(n, 0));
        bool ok = true;
        auto f = [&](int i, int j) -> void
        {
            cnt++;
            c[i][j] ^= 1;
            if (i > 0)
                c[i - 1][j] ^= 1;
            if (i < n - 1)
                c[i + 1][j] ^= 1;
            if (j > 0)
                c[i][j - 1] ^= 1;
            if (j < n - 1)
                c[i][j + 1] ^= 1;
            if (cnt >= ans)
                ok = false;
        };
        for (int j = 0; j < n and ok; j++)
            if ((m >> j) & 1)
                f(0, j);
        for (int i = 1; i < n and ok; i++)
            for (int j = 0; j < n and ok; j++)
                if (c[i - 1][j] != a[i - 1][j])
                    f(i, j);
        for (int i = 0; i < n and ok; i++)
            if (c[n - 1][i] != a[n - 1][i])
                ok = false;
        if (ok)
            ans = min(ans, cnt);
    }
    cout << (ans == LLONG_MAX ? -1 : ans);
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
