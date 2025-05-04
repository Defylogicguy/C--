/*************************
  Author: Defy logic guy
  21:31:54 - 29/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_QHD_STRBEAUTY"

void solve()
{
    string s;
    int k;
    cin >> s >> k;

    int n;
    cin >> n;
    vector<vector<int>> w(26, vector<int>(26, 0));
    for (int i = 0; i < n; i++)
    {
        char x, y;
        int z;
        cin >> x >> y >> z;
        w[x - 'a'][y - 'a'] = z;
    }

    vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(26, vector<int>(k + 1, LLONG_MIN)));

    for (int i = 0; i < 26; i++)
    {
        int idk = (i == s[0] - 'a' ? 0 : 1);
        if (idk <= k)
            dp[1][i][idk] = 0;
    }

    n = s.size();
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int idk = (j == s[i - 1] - 'a' ? 0 : 1);
            for (int l = idk; l <= k; l++)
            {
                int mx = LLONG_MIN;
                for (int u = 0; u < 26; u++)
                {
                    int prv = dp[i - 1][u][l - idk];
                    if (prv == LLONG_MIN)
                        continue;
                    mx = max(mx, prv + w[u][j]);
                }
                dp[i][j][l] = mx;
            }
        }
    }

    int ans = LLONG_MIN;
    for (int i = 0; i < 26; i++)
        ans = max(ans, maxall(dp[n][i]));
    cout << ans << endl;
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
