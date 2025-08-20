/*************************
  Author: Defy logic guy
  10:41:35 - 19/08/2025
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
#define NAME "lostcow"

void solve()
{
    int x, y;
    cin >> x >> y;
    int t = x;
    int b = 1, cnt = 0, cur = 1;
    for (int i = 0;; i++)
    {
        b = (i & 1 ? -1 : 1);
        for (int j = 0;; j += b)
        {
            cnt++;
            x += b;
            if (x == y)
                break;
            if (x == t + cur * b)
                break;
        }
        if (x == y)
            break;
        cur *= 2;
    }
    cout << cnt;
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
