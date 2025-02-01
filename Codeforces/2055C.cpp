/*************************
  Author: Defy logic guy
  21:32:39 - 12/01/2025
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
#define NAME "2055C"

void solve()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    vector<vector<int>> idk(n, vector<int>(m, 0));
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                idk[i][j] = a[i][j];
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }

    int x = 0, y = 0;
    idk[x][y] = 0;
    row[x] += idk[x][y];
    col[y] += idk[x][y];

    for (char c : s)
    {
        if (c == 'R')
            y++;
        else
            x++;
        idk[x][y] = 0;
        row[x] += idk[x][y];
        col[y] += idk[x][y];
    }
    int total = row[0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 0)
            {
                int idk1 = total - (row[i] + col[j] - idk[i][j]);
                idk[i][j] = idk1;
            }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << idk[i][j] << " ";
        cout << endl;
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
    cout.tie(nullptr);

    int tt = 1;
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
