/*************************
  Author: Defy logic guy
  20:37:39 - 19/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "GAME"

void solve()
{
    int n, w;
    cin >> n >> w;
    multiset<pair<int, int>> a[w + 1];
    for (int i = 0; i < n; i++)
    {
        int m, e, s;
        cin >> m >> e >> s;
        a[m].insert({e, s});
    }
    vector<int> dp(w + 1, 0);
    for (int i = 1; i <= w; i++)
        for (int j = 0; j < w / i; j++)
        {
            if (a[i].empty())
                break;
            for (int k = w; k >= i; k--)
                dp[k] = max(dp[k], dp[k - i] + (*prev(a[i].end())).first);
            pair<int, int> t = *prev(a[i].end());
            t.first -= t.second;
            a[i].erase(prev(a[i].end()));
            if (t.first > 0)
                a[i].insert(t);
        }
    cout << maxall(dp);
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
