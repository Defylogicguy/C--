/*************************
  Author: Defy logic guy
  19:48:10 - 18/02/2025
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
#define NAME "B463"

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> y >> x;
    x--, y--;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    string s;
    cin >> s;
    for (char c : s)
    {
        if (c == 'L' && y - 1 >= 0 && a[x][y - 1] == '.')
            y--;
        if (c == 'R' && y + 1 < m && a[x][y + 1] == '.')
            y++;
        if (c == 'U' && x - 1 >= 0 && a[x - 1][y] == '.')
            x--;
        if (c == 'D' && x + 1 < n && a[x + 1][y] == '.')
            x++;
    }

    cout << x + 1 << ' ' << y + 1;
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
