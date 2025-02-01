/*************************
  Author: Defy logic guy
  20:22:35 - 14/01/2025
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
#define NAME "C275B"

int n, m;
vector<string> a;
bool check(int x, int y)
{
    vector<vector<bool>> check(n, vector<bool>(m, false));
    check[x][y] = true;
    for (int i = x; i < n; i++)
    {
        if (a[i][y] == 'W')
            break;
        check[i][y] = true;
        for (int j = y; j < m; j++)
        {
            if (a[i][j] == 'W')
                break;
            check[i][j] = true;
        }
        for (int j = y; j >= 0; j--)
        {
            if (a[i][j] == 'W')
                break;
            check[i][j] = true;
        }
    }

    for (int i = x; i >= 0; i--)
    {
        if (a[i][y] == 'W')
            break;
        check[i][y] = true;
        for (int j = y; j < m; j++)
        {
            if (a[i][j] == 'W')
                break;
            check[i][j] = true;
        }

        for (int j = y; j >= 0; j--)
        {
            if (a[i][j] == 'W')
                break;
            check[i][j] = true;
        }
    }

    for (int i = y; i < m; i++)
    {
        if (a[x][i] == 'W')
            break;
        check[x][i] = true;
        for (int j = x; j < n; j++)
        {
            if (a[j][i] == 'W')
                break;
            check[j][i] = true;
        }
        for (int j = x; j >= 0; j--)
        {
            if (a[j][i] == 'W')
                break;
            check[j][i] = true;
        }
    }
    
    for (int i = y; i >= 0; i--)
    {
        if (a[x][i] == 'W')
            break;
        check[x][i] = true;
        for (int j = x; j < n; j++)
        {
            if (a[j][i] == 'W')
                break;
            check[j][i] = true;
        }
        for (int j = x; j >= 0; j--)
        {
            if (a[j][i] == 'W')
                break;
            check[j][i] = true;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'B' and !check[i][j])
                return false;
    return true;
}

void solve()
{
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'B')
                if (!check(i, j))
                {
                    cout << "No\n";
                    return;
                }
    cout << "Yes\n";
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
