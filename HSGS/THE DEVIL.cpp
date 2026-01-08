/*************************
  Author: Defy logic guy
  14:19:33 - 17/06/2025
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
#define NAME "THE DEVIL"

void solve()
{
    int n;
    cin >> n;
    string q;
    cin >> q;
    string s = " ";
    int len = 0, cur = 0;
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
    for (char c : q)
    {
        if (c == '-')
        {
            for (int i = 1; i <= len; i++)
                cur -= dp[i][len], dp[i][len] = 0;
            len--;
            s.pop_back();
        }
        else
        {
            s += c;
            len++;
            for (int i = 1; i < len - 1; i++)
                dp[i][len] = dp[i + 1][len - 1] && (s[i] == s[len]), cur += dp[i][len];
            dp[len][len] = 1, cur++;
            if (s[len] == s[len - 1])
                dp[len - 1][len] = 1, cur++;
        }
        cout << cur << ' ';
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
