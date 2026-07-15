/*************************
  Author: Defy logic guy
  19:43:25 - 14/07/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "" << p.first << " " << p.second << ""; }
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
#define NAME "perimeter"

const int dx[4] = {0, 0, 1, -1},
          dy[4] = {1, -1, 0, 0};
void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> v;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!vis[i][j] and a[i][j] == '#')
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                vis[i][j] = true;
                int area = 0, peri = 0;
                while (q.size())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    area++;
                    for (int _ = 0; _ < 4; _++)
                    {
                        int nx = x + dx[_], ny = y + dy[_];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] == '.')
                            peri++;
                        else if (!vis[nx][ny])
                        {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                v.emplace_back(area, peri);
            }
    sort(all(v), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first == b.first ? a.second < b.second : a.first > b.first; });
    cout << v[0];
}

signed main()
{
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
