/*************************
 Author: Defy logic guy
11:50:25 - 22/08/2025
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
#define NAME "ABC"

int f(char c, const string &s)
{
    int n = s.size();
    vector<int> pf(n + 1, 0);
    for (int i = 0; i < n; i++)
        pf[i + 1] = pf[i] + (s[i] == c ? 1 : -1);
    vector<pair<int, int>> v;
    v.reserve(n + 1);
    for (int i = 0; i <= n; i++)
        v.emplace_back(pf[i], i);
    sort(all(v));
    vector<int> mn(n + 1, LLONG_MAX);
    for (int i = 0; i <= n; i++)
        if (!i)
            mn[i] = v[i].second;
        else
            mn[i] = min(mn[i - 1], v[i].second);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(all(v), make_pair(pf[i], LLONG_MIN));
        int pos = it - v.begin() - 1;
        if (pos >= 0)
        {
            int j = mn[pos];
            mx = max(mx, i - j);
        }
    }
    return mx;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    cout << max({f('a', s), f('b', s), f('c', s)});
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
