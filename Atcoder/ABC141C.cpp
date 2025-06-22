/*************************
  Author: Defy logic guy
  00:02:18 - 22/06/2025
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
#define NAME "ABC141C"

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    map<int, int> mp;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (int i = 1; i <= n; i++)
        cout << (q - mp[i] < k ? "Yes\n" : "No\n");
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
