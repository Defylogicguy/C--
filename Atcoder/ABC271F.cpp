/*************************
  Author: Defy logic guy
  08:42:01 - 03/06/2025
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
#define NAME "ABC271F"

int n;
vector<int> one, two;
vector<vector<int>> a;

void do1(int i, int j, int x, int y, int cur)
{
    if (i == x and j == y)
    {
        one.pb(cur);
        return;
    }

    if (i < x)
        do1(i + 1, j, x, y, cur ^ a[i + 1][j]);
    if (j < y)
        do1(i, j + 1, x, y, cur ^ a[i][j + 1]);
}

void do2(int i, int j, int x, int y, int cur = 0)
{
    if (i == x and j == y)
    {
        two.pb(cur);
        return;
    }

    if (i > x)
        do2(i - 1, j, x, y, cur ^ a[i - 1][j]);
    if (j > y)
        do2(i, j - 1, x, y, cur ^ a[i][j - 1]);
}

void solve()
{
    cin >> n;
    a.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int x = 0; x < n; x++)
    {
        one.clear(), two.clear();
        int y = n - 1 - x;
        do1(0, 0, x, y, a[0][0]);
        do2(n - 1, n - 1, x, y, a[n - 1][n - 1]);
        sort(all(two));
        for (int i = 0; i < one.size(); i++)
        {
            int cur = one[i];
            cur ^= a[x][y];
            ans += upper_bound(all(two), cur) - lower_bound(all(two), cur);
        }
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
