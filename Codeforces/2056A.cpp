/*************************
  Author: Defy logic guy
  21:36:57 - 17/01/2025
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
#define NAME "2056A"

const int maxn = 1e5 + 5;
vector<vector<bool>> a(maxn, vector<bool>(maxn, false));
void solve()
{
    a.assign(maxn, vector<bool>(maxn, false));
    int n, m;
    cin >> n >> m;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        int one, two;
        cin >> one >> two;
        x += one;
        y += two;
        for (int i = one; i <= one + m - 1; i++)
            for (int j = two; j <= two + m - 1; j++)
                a[i][j] = true;
    }
    int ans = 0;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
        {
            int cur = 4;
            if (i > 0 && a[i - 1][j])
                cur--;
            if (j > 0 && a[i][j - 1])
                cur--;
            if (i < maxn - 1 && a[i + 1][j])
                cur--;
            if (j < maxn - 1 && a[i][j + 1])
                cur--;
            ans += cur;
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
