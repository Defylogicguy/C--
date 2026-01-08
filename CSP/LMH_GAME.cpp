/*************************
  Author: Defy logic guy
  16:22:48 - 19/07/2025
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
#define NAME "LMH_GAME"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    // The answer equals the coefficient of q^n in the product for i=1..m:
    //   F_i(q) = (1 - q^(k+i)) / (1 - q^i)
    // which expands to a finite sum: 1 + q^i + q^(2*i) + … + q^(i*r)
    // where r_max = floor((k + i - 1) / i).
    // We use dp: after processing factors 1..i, dp[s] = coefficient of q^s.
    vector<int> dp(n + 1, 0), nxt(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        int R = (k + i - 1) / i;  // maximum multiplier for q^i we can use from factor i
        fill(nxt.begin(), nxt.end(), 0);
        // Convolve current dp with the polynomial P(q)=1 + q^i + q^(2*i)+...+q^(R*i)
        for (int s = 0; s <= n; s++) {
            if (dp[s] == 0)
                continue;
            for (int r = 0; r <= R; r++) {
                int pos = s + i * r;
                if (pos > n)
                    break;
                nxt[pos] = (nxt[pos] + dp[s]) % MOD;
            }
        }
        dp.swap(nxt);
    }
    cout << dp[n] % MOD <<}

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
