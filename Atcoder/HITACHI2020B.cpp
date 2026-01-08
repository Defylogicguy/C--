/*************************
  Author: Defy logic guy
  20:49:36 - 02/06/2025
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
#define NAME "HITACHI2020B"

void solve()
{
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> one(a), two(b);
    for (int i = 0; i < a; i++)
        cin >> one[i];
    for (int i = 0; i < b; i++)
        cin >> two[i];
    int onemn = min_element(all(one)) - one.begin();
    int twomn = min_element(all(two)) - two.begin();
    int mn = one[onemn] + two[twomn];
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        mn = min(mn, one[x] + two[y] - c);
    }
    cout << mn << endl;
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
