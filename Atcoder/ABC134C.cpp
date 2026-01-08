/*************************
  Author: Defy logic guy
  16:11:54 - 22/06/2025
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
#define NAME "ABC134C"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0, smx = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        if (x >= mx)
        {
            smx = mx;
            mx = x;
        }
        else if (x >= smx)
            smx = x;
    }

    for (int i : a)
        cout << (i == mx ? smx : mx) << '\n';
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
