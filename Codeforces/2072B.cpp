/*************************
  Author: Defy logic guy
  21:40:28 - 25/02/2025
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
#define NAME "2072B"

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = count(all(s), '_');
    int two = count(all(s), '-');
    if (two < 2)
    {
        cout << 0 << endl;
        return;
    }

    int l = (two / 2), r = two - l;
    cout << one * l * r << endl;
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
