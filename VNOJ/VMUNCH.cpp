/*************************
  Author: Defy logic guy
  20:48:59 - 07/07/2026
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
#define NAME "VMUNCH"

const int dx[4] = {1, -1, 0, 0},
          dy[4] = {0, 0, 1, -1};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'C')
            {
                q.push({i, j});
                break;
            }
    vector<vector<int>> c(n, vector<int>(m, LLONG_MAX));
    c[q.front().first][q.front().second] = 0;
    while (q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and a[nx][ny] != '*' and c[nx][ny] > c[x][y] + 1)
            {
                q.push(make_pair(nx, ny));
                c[nx][ny] = c[x][y] + 1;
            }
        }
    }
    cout << c[0][0];
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
