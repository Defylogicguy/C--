/*************************
  Author: Defy logic guy
  22:14:44 - 17/07/2026
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "idk"

const int dx[4] = {1, 0, 0, -1},
          dy[4] = {0, -1, 1, 0};
const char c[4] = {'D', 'L', 'R', 'U'};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k & 1)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x, y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'X')
            {
                x = i, y = j;
                break;
            }
    vector<vector<int>> d(n, vector<int>(m, LLONG_MAX));
    d[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (q.size())
    {
        auto [i, j] = q.front();
        q.pop();
        for (int _ = 0; _ < 4; _++)
        {
            int nx = i + dx[_], ny = j + dy[_];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] == '*' or d[nx][ny] != LLONG_MAX)
                continue;
            d[nx][ny] = d[i][j] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    string ans;
    for (int i = 1; i <= k; i++)
    {
        bool flag = true;
        for (int _ = 0; _ < 4; _++)
        {
            int nx = x + dx[_], ny = y + dy[_];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m or a[nx][ny] == '*')
                continue;
            int r = k - i;
            if (d[nx][ny] != LLONG_MAX and d[nx][ny] <= r and (r - d[nx][ny]) % 2 == 0)
            {
                flag = false;
                ans += c[_], x = nx, y = ny;
                break;
            }
        }
        if (flag)
        {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    cout << ans;
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
