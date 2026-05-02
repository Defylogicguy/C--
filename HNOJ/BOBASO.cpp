/*************************
  Author: Defy logic guy
  18:46:38 - 10/04/2026
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
#define NAME "BOBASO"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k, 0);
    for (int i = 0; i < k; i++)
    {
        cnt[i] = n / k;
        if (i != 0)
            cnt[i] += (i <= (n % k));
    }
    cerr << cnt << '\n';
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (!cnt[i])
            continue;
        int j = (k - i) % k;
        if (!cnt[j])
            continue;
        if ((2 * i) % k == 0)
            ans += cnt[i] * cnt[j] * cnt[i];
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
