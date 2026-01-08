/*************************
  Author: Defy logic guy
  10:42:39 - 22/02/2025
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
#define NAME "HASH_DATTEN"

vector<int> hashing(const string &s)
{
    int n = s.size();
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
        hash[i + 1] = (hash[i] * 997 + (s[i] - 'a')) % MOD;
    return hash;
}

vector<int> compute(int n)
{
    vector<int> Pow(n + 1, 0);
    Pow[0] = 1;
    for (int i = 1; i <= n; i++)
        Pow[i] = (Pow[i - 1] * 997) % MOD;
    return Pow;
}

int get(const vector<int> &hash, const vector<int> &Pow, int l, int r)
{
    int val = hash[r + 1] - (hash[l] * Pow[r - l + 1] % MOD);
    if (val < 0)
        val += MOD;
    return val;
}

vector<int> find(const string &s, const string &a, const vector<int> &hash, const vector<int> &Pow)
{
    vector<int> o;
    int n = s.size(), m = a.size();
    if (m > n)
        return o;
    int pat = 0;
    for (char c : a)
        pat = (pat * 997 + (c - 'a')) % MOD;
    for (int i = 0; i <= n - m; i++)
    {
        int cur = get(hash, Pow, i, i + m - 1);
        if (cur == pat)
            o.pb(i);
    }
    return o;
}

void solve()
{
    int k;
    string s, a, b;
    cin >> k >> s >> a >> b;
    int n = s.size(), nA = a.size(), nB = b.size();

    vector<int> hash = hashing(s);
    vector<int> Pow = compute(n);

    vector<int> occA = find(s, a, hash, Pow);
    vector<int> occB = find(s, b, hash, Pow);

    bool flag = false;
    for (int posA : occA)
    {
        auto it = lower_bound(all(occB), posA);
        if (it != occB.end())
        {
            int posB = *it;
            if (posB - posA <= nA + k)
            {
                flag = true;
                break;
            }
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
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

    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
