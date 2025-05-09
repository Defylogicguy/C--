/*************************
  Author: Defy logic guy
  23:22:34 - 05/05/2025
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
#define NAME "ABC404B"

void solve()
{
    int n;
    cin >> n;
    vector<vector<bool>> a(n, vector<bool>(n)), b(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (c == '#');
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            b[i][j] = (c == '#');
        }
    auto cnt = [n](vector<vector<bool>> a, vector<vector<bool>> b) -> int
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cnt += (a[i][j] ^ b[i][j]);
        return cnt;
    };

    auto rotate = [n](vector<vector<bool>> &a) -> void
    {
        vector<vector<bool>> res(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[j][n - i - 1] = a[i][j];
        a = res;
    };

    int ans = cnt(a, b);
    rotate(a);
    ans = min(ans, cnt(a, b) + 1);
    rotate(a);
    ans = min(ans, cnt(a, b) + 2);
    rotate(a);
    ans = min(ans, cnt(a, b) + 3);
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
