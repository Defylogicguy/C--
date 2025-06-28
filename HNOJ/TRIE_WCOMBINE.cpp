/*************************
  Author: Defy logic guy
  11:15:50 - 28/06/2025
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
#define NAME "TRIE_WCOMBINE"

const int maxn = 5005, maxk = 1000005;
int nxt[maxk][26], e[maxk], dp[maxn];
void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int cur = 1;
    while (k--)
    {
        string t;
        cin >> t;
        int pos = 0;
        for (char c : t)
        {
            if (nxt[pos][c - 'a'] == 0)
                nxt[pos][c - 'a'] = cur++;
            pos = nxt[pos][c - 'a'];
        }
        e[pos] = 1;
    }
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int pos = 0, res = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (!nxt[pos][s[j] - 'a'])
            {
                dp[i] = res;
                break;
            }
            pos = nxt[pos][s[j] - 'a'];
            if (e[pos])
                res = (res + dp[j + 1]) % MOD;
        }
        dp[i] = res;
    }
    cout << dp[0];
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
