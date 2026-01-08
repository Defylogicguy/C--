/*************************
  Author: Defy logic guy
  19:55:32 - 19/09/2025
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
#define NAME "KNAPSACK_3"

struct item
{
    int k, w, v;
    item(int k = 0, int w = 0, int v = 0) : k(k), w(w), v(v) {}
};

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<item> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].k >> a[i].w >> a[i].v;

    vector<int> dp(w + 1, 0ll);
    for (int i = 0; i < n; i++)
        for (int j = 1; a[i].k > 0; j *= 2)
        {
            int t = min(j, a[i].k);
            for (int k = w; k >= t * a[i].w; k--)
                dp[k] = max(dp[k], dp[k - t * a[i].w] + t * a[i].v);
            a[i].k -= t;
        }
    cout << dp[w];
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
