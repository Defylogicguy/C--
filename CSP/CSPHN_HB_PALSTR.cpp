/*************************
  Author: Defy logic guy
  14:36:56 - 15/03/2025
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
#define NAME "CSPHN_HB_PALSTR"

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> hash(n + 1, 0), rev(n + 1, 0), Pow(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        hash[i] = (hash[i - 1] * 31 + (s[i - 1] - 'a')) % MOD;
        Pow[i] = (Pow[i - 1] * 31) % MOD;
    }
    reverse(all(s));
    for (int i = 1; i <= n; i++)
        rev[i] = (rev[i - 1] * 31 + (s[i - 1] - 'a')) % MOD;
    
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int lhash = (hash[r] - (hash[l - 1] * Pow[r - l + 1]) % MOD + MOD) % MOD;
        int rhash = (rev[n - l + 1] - (rev[n - r] * Pow[r - l + 1]) % MOD + MOD) % MOD;
        cout << (lhash == rhash ? "YES\n" : "NO\n");
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
