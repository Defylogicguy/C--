/*************************
  Author: Defy logic guy
  11:19:20 - 08/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "MPT"

void solve()
{
    int n, m;
    cin >> n >> m;

    pair<int, int> st, end;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
                st = {i, j};
            else if (a[i][j] == 'T')
                end = {i, j};
        }
 
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push(st);
    d[st.first][st.second] = 0;

    pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (q.size())
    {
        pair<int, int> u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = u.first + dir[i].first, y = u.second + dir[i].second;
            if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '*')
                continue;
            if (d[x][y] == -1 || d[x][y] > d[u.first][u.second] + 1)
            {
                d[x][y] = d[u.first][u.second] + 1;
                q.push({x, y});
            }
        }
    }

    cout << d[end.first][end.second];
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
