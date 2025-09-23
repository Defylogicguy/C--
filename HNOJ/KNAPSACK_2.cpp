/*************************
  Author: Defy logic guy
  18:51:26 - 19/09/2025
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
#define NAME "KNAPSACK_2"

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    vector<int> dp(w + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = a[i].first; j <= w; j++)
            dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
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
