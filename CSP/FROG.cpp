/*************************
  Author: Defy logic guy
  19:36:08 - 20/01/2025
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
#define NAME "FROG"

void solve()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[0][i] = a[0][i];
    int sz = 2 * k + 1;
    for (int i = 1; i < m; i++)
    {
        vector<int> idk = dp[i - 1];
        vector<int> ans;
        deque<int> dq;
        for (int j = 0; j < k; j++)
        {
            idk.pb(0);
            idk.insert(idk.begin(), 0);
        }

        int j = 0;
        for (; j < sz; j++)
        {
            while (dq.size() and idk[j] >= idk[dq.back()])
                dq.pop_back();
            dq.pb(j);
        }

        for (; j < idk.size(); j++)
        {
            ans.pb(idk[dq.front()]);

            while (dq.size() and dq.front() <= j - sz)
                dq.pop_front();

            while (dq.size() and idk[j] >= idk[dq.back()])
                dq.pop_back();

            dq.pb(j);
        }

        ans.pb(idk[dq.front()]);
        for (int j = 0; j < n; j++)
            dp[i][j] = ans[j] + a[i][j];
    }
    cout << *max_element(all(dp[m - 1])) << endl;
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
