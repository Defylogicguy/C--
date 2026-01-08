/*************************
  Author: Defy logic guy
  17:49:33 - 22/08/2025
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
#define NAME "SICK"

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<string> p = {"abc", "acb", "bac", "bca", "cab", "cba"};
    int k = p.size();
    vector<vector<int>> pf(k, vector<int>(n + 1, 0));
    for (int j = 0; j < k; j++)
        for (int i = 1; i <= n; i++)
            pf[j][i] = pf[j][i - 1] + (s[i - 1] != p[j][(i - 1) % 3]);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = LLONG_MAX;
        for (int j = 0; j < k; j++)
            ans = min(ans, pf[j][r] - pf[j][l - 1]);
        cout << ans << '\n';
    }
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
