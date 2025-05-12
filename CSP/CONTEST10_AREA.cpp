/*************************
  Author: Defy logic guy
  16:13:55 - 10/05/2025
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
#define NAME "CONTEST10_AREA"

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int r1 = n - abs(x - y), c1 = n + 1 - r1;
    int r2 = n - abs((x + y) - (n + 1)), c2 = n + 1 - r2;
    cout <<  2 * r1 * c1 - r1 - c1 + 1 + 2 * r2 * c2 - r2 - c2 + 1 - (2 * c1 * c2 - c1 - c2 + 1);
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
