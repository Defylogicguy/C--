/*************************
  Author: Defy logic guy
  18:54:22 - 10/10/2025
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
#define NAME "EVENARR"

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
map<int, int> val;

int f(int x)
{
    if (val.find(x) != val.end())
        return val[x];
    return val[x] = rng() % LLONG_MAX;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), pf(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = f(x);
        pf[i + 1] = pf[i] ^ a[i];
    }

    map<int, int> mp;
    for (int i : pf)
        mp[i]++;

    int ans = 0;
    for (auto &[u, v] : mp)
        ans += v * (v - 1) / 2;

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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
