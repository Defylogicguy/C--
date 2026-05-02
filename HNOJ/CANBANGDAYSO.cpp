/*************************
  Author: Defy logic guy
  21:18:26 - 02/05/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
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
#define NAME "CANBANGDAYSO"

void solve()
{
    int n;
    cin >> n;
    vector<int> pf(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pf[i] = pf[i - 1] + x;
    }
    multiset<int> mst;
    int ans = LLONG_MAX;
    for (int k = 1; k <= n - 1; k++)
    {
        mst.insert(pf[k]);
        int x = pf[n] - pf[k];
        auto it = mst.lower_bound(x);
        if (it != mst.end())
            ans = min(ans, abs(*it - x));
        if (it != mst.begin())
            --it, ans = min(ans, abs(*it - x));
    }
    cout << ans;
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
