/*************************
  Author: Defy logic guy
  16:02:16 - 15/03/2025
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
#define NAME "REPEATED_SUBSTRING"
#define MOD1 998244353

string ans;
bool f(int mid, const string &s)
{
    vector<int> hash1(s.size() + 1, 0), Pow(s.size() + 1, 1), hash2(s.size() + 1, 0);

    for (int i = 1; i < Pow.size(); i++)
        Pow[i] = (Pow[i - 1] * 31) % MOD;

    for (int i = 1; i <= s.size(); i++)
    {
        hash1[i] = (hash1[i - 1] * 31 + (s[i - 1] - 'a')) % MOD;
        hash2[i] = (hash2[i - 1] * 31 + (s[i - 1] - 'a')) % MOD1;
    }
    unordered_map<int, vector<int>> mp1, mp2;
    for (int i = mid; i <= s.size(); i++)
    {
        int val = (hash1[i] - (hash1[i - mid] * Pow[mid]) % MOD + MOD) % MOD;
        mp1[val].pb(i - mid + 1);
    }

    for (int i = mid; i <= s.size(); i++)
    {
        int val = (hash2[i] - (hash2[i - mid] * Pow[mid]) % MOD1 + MOD1) % MOD1;
        mp2[val].pb(i - mid + 1);
    }

    for (const auto &it : mp1)
    {
        if (it.second.size() < 2)
            continue;
        ans = s.substr(it.second[0] - 1, mid);
        if (mp2.find(it.first) != mp2.end() && mp2[it.first].size() >= 2)
        {
            ans = s.substr(mp2[it.first][0] - 1, mid);
            return true;
        }
    }
    return false;
}

void solve()
{
    string s;
    cin >> s;

    int l = 1, r = s.size();
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(mid, s))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << (ans.size() ? ans : "-1") << endl;
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
