/*************************
  Author: Defy logic guy
  22:37:11 - 19/08/2025
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
#define NAME "blist"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(1000, 0);
    for (int i = 0; i < n; i++)
    {
        int s, t, b;
        cin >> s >> t >> b;
        for (int j = s - 1; j < t; j++)
            a[j] += b;
    }
    cout << maxall(a);
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
