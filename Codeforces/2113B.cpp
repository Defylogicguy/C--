/*************************
  Author: Defy logic guy
  11:41:45 - 20/07/2025
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
#define NAME "2113B"

void solve()
{
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int rx1 = (x1 % a + a) % a;
    int rx2 = (x2 % a + a) % a;
    int ry1 = (y1 % b + b) % b;
    int ry2 = (y2 % b + b) % b;
    cout << (((rx1 == rx2) and ((x1 != x2) or (ry1 == ry2))) or ((ry1 == ry2) and (y1 != y2)) ? "Yes\n" : "No\n");
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
