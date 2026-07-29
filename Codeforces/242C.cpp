/*************************
  Author: Defy logic guy
  15:26:05 - 18/07/2026
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
#define NAME "242C"

const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1},
          dy[8] = {1, -1, 0, 0, 1, 1, -1, -1},
          INF = 1e9;
void solve()
{
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int n;
    cin >> n;
    set<pair<int, int>> st;
    while (n--)
    {
        int r, a, b;
        cin >> r >> a >> b;
        for (int i = a; i <= b; i++)
            st.insert(make_pair(r, i));
    }
    set<pair<int, int>> vis;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(sx, sy), 0));
    vis.insert(make_pair(sx, sy));
    while (q.size())
    {
        auto [p, s] = q.front();
        q.pop();
        if (p == make_pair(ex, ey))
        {
            cout << s;
            return;
        }
        for (int _ = 0; _ < 8; _++)
        {
            int nx = p.first + dx[_], ny = p.second + dy[_];
            if (!st.count(make_pair(nx, ny)) or vis.count(make_pair(nx, ny)))
                continue;
            vis.insert(make_pair(nx, ny));
            q.push(make_pair(make_pair(nx, ny), s + 1));
        }
    }
    cout << -1;
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
