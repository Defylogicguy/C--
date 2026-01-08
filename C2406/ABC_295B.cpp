/*************************
  Author: Defy logic guy
  19:56:31 - 11/02/2025
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
#define NAME "ABC_295B"

struct mine
{
    int x, y, power;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<mine> idk;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if ('1' <= a[i][j] and a[i][j] <= '9')
                idk.pb({i, j, a[i][j] - '0'});
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != '.')
            {
                for (mine it : idk)
                    if (abs(it.x - i) + abs(it.y - j) <= it.power)
                    {
                        a[i][j] = '.';
                        break;
                    }
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j];
            if (j == m - 1)
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
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
