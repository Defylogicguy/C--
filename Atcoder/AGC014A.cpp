/*************************
  Author: Defy logic guy
  15:39:45 - 30/05/2025
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
#define NAME "AGC014A"

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if( a == b and b == c and (a & 1))
    {
        cout << 0 << endl;
        return;
    }
    if (a == b and b == c and !(a & 1))
    {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    while (!(a & 1) and !(b & 1) and !(c & 1))
    {
        int a1 = a, b1 = b, c1 = c;
        a = (a1 + b1) / 2;
        b = (b1 + c1) / 2;
        c = (c1 + a1) / 2;
        cnt++;
    }
    cout << cnt << endl;
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
