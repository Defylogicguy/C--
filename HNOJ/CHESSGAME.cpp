/*************************
  Author: Defy logic guy
  19:55:27 - 23/01/2026
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
#define NAME "CHESSGAME"

int dx[2][8] = {{1, 1, -1, -1, 2, 2, -2, -2}, {1, 1, 1, 0, 0, -1, -1, -1}},
    dy[2][8] = {{2, -2, -2, 2, -1, 1, -1, 1}, {-1, 0, 1, -1, 1, 1, -1, 0}};

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<tuple<int, int, int>> p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != '.' and a[i][j] != '#')
                p.emplace_back(i, j, (a[i][j] == 'T'));
    vector<vector<vector<int>>> d(n, vector<vector<int>>(n, vector<int>(p.size(), -1)));
    for (int _ = 0; _ < p.size(); _++)
    {
        auto [x, y, t] = p[_];
        d[x][y][_] = 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (q.size())
        {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 8; k++)
            {
                int nx = i + dx[t][k], ny = j + dy[t][k];
                if (nx < 0 or nx >= n or ny < 0 or ny >= n or a[nx][ny] == '#')
                    continue;
                if (d[nx][ny][_] == -1)
                {
                    d[nx][ny][_] = d[i][j][_] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int mn = LLONG_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '#')
                continue;
            int mx = 0;
            bool ok = true;
            for (int k = 0; k < p.size(); k++)
            {
                if (d[i][j][k] == -1)
                {
                    ok = false;
                    break;
                }
                mx = max(mx, d[i][j][k]);
            }
            if (ok)
                for (int k = 0; k < p.size(); k++)
                    if ((mx - d[i][j][k]) % 2 != 0)
                    {
                        ok = false;
                        break;
                    }
            if (ok)
                mn = min(mn, mx);
        }
    cout << (mn == LLONG_MAX ? -1 : mn);
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
