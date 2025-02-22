/*************************
  Author: Defy logic guy
  08:51:08 - 22/02/2025
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
#define NAME "HASH_RESUBSTR"

bool f(int mid, const vector<int> &hash)
{
    int Pow = 1;
    for (int i = 1; i <= mid; i++)
        Pow = (Pow * 997) % MOD;
    unordered_map<int, vector<int>> mp;
    for (int i = mid; i <= hash.size(); i++)
    {
        int val = (hash[i] - (Pow * hash[i - mid]) % MOD + MOD) % MOD;
        mp[val].pb(i - mid + 1);
    }
    for (const auto &it : mp)
    {
        if (it.second.size() < 2)
            continue;
        const vector<int> &a = it.second;
        for (int i = 1; i < a.size(); i++)
            if (a[i] - a[0] >= mid)
                return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> hash(n + 1, 0);
    for (int i = 1; i <= n; i++)
        hash[i] = (hash[i - 1] * 997 + (s[i - 1] - 'a' + 1)) % MOD;

    int l = 0, r = n;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(mid, hash))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
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
