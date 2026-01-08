/*************************
  Author: Defy logic guy
  19:39:36 - 19/03/2025
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
#define NAME "REPEATING_SUBSTRING"

string res = "-1";

int get(int l, int r, const vector<int> &hash, const vector<int> &Pow)
{
    int val = hash[r + 1] - (hash[l] * Pow[r - l + 1] % MOD);
    val %= MOD;
    if (val < 0)
        val += MOD;
    return val;
}

bool f(int mid, const string &s, const vector<int> &hash, const vector<int> &Pow)
{
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i <= (int)s.size() - mid; i++)
    {
        int cur = get(i, i + mid - 1, hash, Pow);
        if (mp.find(cur) != mp.end())
            for (int j : mp[cur])
                if (s.compare(j, mid, s, i, mid) == 0)
                {
                    res = s.substr(j, mid);
                    return true;
                }
        mp[cur].pb(i);
    }
    return false;
}

void solve()
{
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << res << endl;
        return;
    }

    int n = s.size();
    vector<int> hash(n + 1, 0), Pow(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        hash[i] = (hash[i - 1] * 31 + (s[i - 1] - 'a')) % MOD;
        Pow[i] = (Pow[i - 1] * 31) % MOD;
    }

    int l = 1, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f(mid, s, hash, Pow))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << res;
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
