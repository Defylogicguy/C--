/*************************
  Author: Defy logic guy
  22:09:14 - 17/06/2026
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
#define NAME "1724"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(n, LLONG_MAX));
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[v - 1][u - 1] = min(a[v - 1][u - 1], w);
    }
    auto f = [n](const vector<vector<int>> &a, const vector<vector<int>> &b) -> vector<vector<int>>
    {
        vector<vector<int>> ans(n, vector<int>(n, LLONG_MAX));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                if (a[k][i] != LLONG_MAX)
                    for (int j = 0; j < n; j++)
                        if (b[j][k] != LLONG_MAX)
                            ans[j][i] = min(ans[j][i], b[j][k] + a[k][i]);
        return ans;
    };
    auto binpow = [&](vector<vector<int>> a, int k) -> vector<vector<int>>
    {
        vector<vector<int>> res(n, vector<int>(n, LLONG_MAX));
        for (int i = 0; i < n; i++)
            res[i][i] = 0;
        while (k > 0)
        {
            if (k & 1)
                res = f(res, a);
            a = f(a, a);
            k >>= 1;
        }
        return res;
    };
    auto ans = binpow(a, k);
    cout << (ans[n - 1][0] == LLONG_MAX ? -1 : ans[n - 1][0]);
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
