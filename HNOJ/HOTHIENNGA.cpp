/*************************
  Author: Defy logic guy
  20:46:49 - 24/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "HOTHIENNGA"

struct coor
{
    int idx;
    int x, y;
    int dis = 0;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'L')
                q.push({i, j}), vis[i][j] = true;
        }

    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = 0;
    while (q.size())
    {
        int sz = q.size();
        while (sz--)
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int u = x + dir[i].first, v = y + dir[i].second;
                if (u < 0 || u >= n || v < 0 || v >= m || vis[u][v] || a[u][v] == 'X')
                    continue;
                vis[u][v] = true;
                q.push({u, v});
            }
        }
        ans++;
    }

    cout << ans << endl;
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
