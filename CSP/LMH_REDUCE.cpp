/*************************
  Author: Defy logic guy
  21:22:11 - 01/09/2025
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
#define NAME "LMH_REDUCE"

const int maxn = 207;
int a[maxn], dp[maxn][20005];
void solve()
{
    int n, v;
    cin >> n >> v;
    int s = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s += a[i];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = s; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
                dp[i][j] |= dp[i - 1][j - a[i]];
        }
    s = (s - v) / 2;
    vector<int> ans(n, 1);
    int cnt = n, i = n;
    while (i > 0)
        if (dp[i - 1][s])
            i--;
        else
        {
            ans[i - 1] = -1;
            cnt--;
            s -= a[i];
            i--;
        }
    vector<int> res;
    while (cnt > 1)
        for (int i = 0; i < ans.size(); i++)
            if (i == ans.size() - 1 and ans[i] == -1 and ans[0] == 1)
            {
                res.pb(i);
                ans.erase(ans.begin());
                cnt--;
                break;
            }
            else if (ans[i] == -1 and ans[i + 1] == 1)
            {
                res.pb(i);
                ans.erase(ans.begin() + i + 1);
                cnt--;
                break;
            }
    while (ans.size() > 1)
        for (int i = 0; i < ans.size(); i++)
            if (ans[i] == 1)
            {
                res.pb(i);
                if (i == ans.size() - 1)
                    ans.erase(ans.begin());
                else
                    ans.erase(ans.begin() + i + 1);
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
