/*************************
  Author: Defy logic guy
  22:57:52 - 23/05/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_DHSP2023_CAU2"

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int bfs(const vector<vector<int>> &a, vector<vector<int>> &vis, int x, int y)
{
    int m = a.size(), n = a[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    int cnt = 0;

    while (!q.empty())
    {
        auto [u, v] = q.front();
        q.pop();
        int h = a[u][v];

        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int x1 = u + dx[i], y1 = v + dy[i];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n)
                cnt += max(0LL, h - a[x1][y1]);
            else
                cnt += h;

            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !vis[x1][y1] && a[x1][y1])
            {
                vis[x1][y1] = 1;
                q.push({x1, y1});
            }
        }
    }
    return cnt;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int cnt = 0, sum = 0, mx = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && a[i][j])
            {
                cnt++;
                int faces = bfs(a, vis, i, j);
                sum += faces;
                mx = max(mx, faces);
            }
        }
    }

    cout << cnt << endl
         << sum << endl
         << mx << endl;
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
