/*************************
  Author: Defy logic guy
  21:31:50 - 26/11/2025
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
    for (auto it = c.begin(); it != c.end(); ++it)
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
#define NAME "1192"

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> v(n, vector<int>(m, 0));
    auto bfs = [&](int idx, int x, int y) -> void
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (q.size())
        {
            auto [i, j] = q.front();
            q.pop();
            if (0 > i or i >= n or j < 0 or j >= m or a[i][j] == '#' or v[i][j] > 0)
                continue;
            v[i][j] = idx;
            for (int _ = 0; _ < 4; _++)
                q.push({i + dx[_], j + dy[_]});
        }
    };
    int cur = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != '#' and v[i][j] == 0)
                bfs(cur++, i, j);
    cout << cur - 1;
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
