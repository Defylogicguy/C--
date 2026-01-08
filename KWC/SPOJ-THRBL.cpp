/*************************
  Author: Defy logic guy
  23:57:57 - 05/08/2025
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
#define NAME "SPOJ-THRBL"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<vector<int>> st(n + 1, vector<int>(21));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st[i][0] = a[i];
    }
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    vector<int> lg(n + 2);
    lg[1] = 0;
    for (int i = 2; i <= n + 1; i++)
        lg[i] = lg[i / 2] + 1;
    int ans = 0;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        r--;
        ans += (max(st[l][lg[r - l + 1]], st[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]) <= a[l]);
    }
    cout << ans;
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
