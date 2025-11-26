/*************************
  Author: Defy logic guy
  21:39:08 - 26/11/2025
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
#define NAME "1193"

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const char ds[4] = {'R', 'L', 'D', 'U'};

struct node
{
    int x, y;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    node st, en;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
                st = {i, j};
            if (a[i][j] == 'B')
                en = {i, j};
        }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<node>> par(n, vector<node>(m, {-1, -1}));
    vector<vector<char>> dir(n, vector<char>(m, '?'));

    queue<node> q;
    q.push(st);
    vis[st.x][st.y] = true;

    bool flag = false;

    while (q.size())
    {
        node cur = q.front();
        q.pop();
        if (cur.x == en.x && cur.y == en.y)
        {
            flag = true;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || a[nx][ny] == '#')
                continue;

            vis[nx][ny] = true;
            par[nx][ny] = cur;
            dir[nx][ny] = ds[k];
            q.push({nx, ny});
        }
    }

    if (!flag)
    {
        cout << "NO";
        return;
    }

    string res;
    node cur = en;

    while (cur.x != st.x || cur.y != st.y)
    {
        res.pb(dir[cur.x][cur.y]);
        cur = par[cur.x][cur.y];
    }

    reverse(all(res));

    cout << "YES\n"
         << res.size() << '\n'
         << res;
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
