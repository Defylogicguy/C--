/*************************
  Author: Defy logic guy
  22:46:12 - 04/09/2025
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
#define NAME "2B"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int>> cnt2(n, vector<int>(n, 0)), cnt5(n, vector<int>(n, 0));
    vector<vector<int>> dp2(n, vector<int>(n, LLONG_MAX)), dp5(n, vector<int>(n, LLONG_MAX));
    vector<vector<char>> path2(n, vector<char>(n)), path5(n, vector<char>(n));

    int zeri = -1, zerj = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
                zeri = i, zerj = j;
            else
            {
                int cnt = 0;
                while (a[i][j] % 2 == 0)
                    a[i][j] /= 2, cnt++;
                cnt2[i][j] = cnt;
                cnt = 0;
                while (a[i][j] % 5 == 0)
                    a[i][j] /= 5, cnt++;
                cnt5[i][j] = cnt;
            }

    dp2[0][0] = (a[0][0] == 0 ? 1 : cnt2[0][0]);
    dp5[0][0] = (a[0][0] == 0 ? 1 : cnt5[0][0]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                int val2 = dp2[i - 1][j] + (a[i][j] == 0 ? 1 : cnt2[i][j]);
                int val5 = dp5[i - 1][j] + (a[i][j] == 0 ? 1 : cnt5[i][j]);
                if (val2 < dp2[i][j])
                    dp2[i][j] = val2, path2[i][j] = 'D';
                if (val5 < dp5[i][j])
                    dp5[i][j] = val5, path5[i][j] = 'D';
            }
            if (j > 0)
            {
                int val2 = dp2[i][j - 1] + (a[i][j] == 0 ? 1 : cnt2[i][j]);
                int val5 = dp5[i][j - 1] + (a[i][j] == 0 ? 1 : cnt5[i][j]);
                if (val2 < dp2[i][j])
                    dp2[i][j] = val2, path2[i][j] = 'R';
                if (val5 < dp5[i][j])
                    dp5[i][j] = val5, path5[i][j] = 'R';
            }
        }

    int ans = min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]);

    string path = "";
    if (ans > 1 && zeri != -1)
    {
        cout << 1 << '\n';
        for (int i = 0; i < zeri; i++)
            cout << 'D';
        for (int j = 0; j < zerj; j++)
            cout << 'R';
        for (int i = zeri; i < n - 1; i++)
            cout << 'D';
        for (int j = zerj; j < n - 1; j++)
            cout << 'R';
        return;
    }

    int x = n - 1, y = n - 1;
    bool use2 = dp2[n - 1][n - 1] < dp5[n - 1][n - 1];
    while (x > 0 || y > 0)
    {
        if (use2)
        {
            if (path2[x][y] == 'D')
            {
                path += 'D';
                x--;
            }
            else
            {
                path += 'R';
                y--;
            }
        }
        else
        {
            if (path5[x][y] == 'D')
            {
                path += 'D';
                x--;
            }
            else
            {
                path += 'R';
                y--;
            }
        }
    }

    reverse(all(path));
    cout << ans << '\n'
         << path;
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
