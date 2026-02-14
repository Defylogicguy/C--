/*************************
  Author: Defy logic guy
  19:28:06 - 23/01/2026
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
#define NAME "GOLF"

int dx[4] = {1, -1, 0, 0},
    dy[4] = {0, 0, 1, -1};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    bool flag = false;
    for (int i = 0; i < n and !flag; i++)
        for (int j = 0; j < m and !flag; j++)
            if (a[i][j] == 'S')
            {
                d[i][j] = 0;
                q.push({i, j});
                flag = true;
            }
    while (q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int _ = 0; _ < 4; _++)
            for (int i = 1; i <= k; i++)
            {
                int nx = x + dx[_] * i,
                    ny = y + dy[_] * i;
                if (nx < 0 or nx >= n or ny < 0 or ny >= m)
                    break;
                if (a[nx][ny] == '#' )
                    break;
                if (d[nx][ny] != -1)
                {
                    if (d[nx][ny] <= d[x][y] + 1)
                        break;
                    else
                        continue;
                }
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'G')
            {
                cout << d[i][j];
                return;
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
