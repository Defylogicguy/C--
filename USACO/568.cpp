/*************************
  Author: Defy logic guy
  10:34:03 - 19/08/2025
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
#define NAME "speeding"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(100), b(100);
    int lst = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = lst; j < lst + x; j++)
            a[j] = y;
        lst += x;
    }
    lst = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = lst; j < lst + x; j++)
            b[j] = y;
        lst += x;
    }
    int ans = LLONG_MIN;
    for (int i = 0; i < 100; i++)
        ans = max(ans, b[i] - a[i]);
    cout << max(ans, 0ll);
}

signed main()
{
    if (fopen(NAME ".in", "r"))
    {
        freopen(NAME ".in", "r", stdin);
        freopen(NAME ".out", "w", stdout);
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
