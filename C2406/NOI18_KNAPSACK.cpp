/*************************
  Author: Defy logic guy
  22:44:38 - 14/01/2025
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
#define NAME "NOI18_KNAPSACK"

void solve()
{
    int s, n;
    cin >> s >> n;
    vector<tuple<int, int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
    
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
