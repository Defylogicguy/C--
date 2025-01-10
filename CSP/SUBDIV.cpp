/*************************
  Author: Defy logic guy
  14:09:01 - 04/01/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "SUBDIV"

int n, k;
int mod(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans = (ans * 10 + (s[i] - '0')) % k;
    return ans;
}

void solve()
{
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        a[i] = mod(x);
    }
    vector<int> pf(n + 1, 0);
    partial_sum(all(a), pf.begin() + 1, [](int a, int b)
                { return (a + b) % k; });
    map<int, int> mp;
    for (int i : pf)
        mp[i]++;
    int ans = 0;
    for (auto it : mp)
    {
        int x = it.second;
        ans += x * (x - 1) / 2;
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
