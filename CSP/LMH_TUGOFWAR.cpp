/*************************
  Author: Defy logic guy
  23:22:11 - 07/10/2025
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
#define NAME "LMH_TUGOFWAR"

const int maxn = 105, maxs = 1e6 + 5;
bitset<maxs> dp;
int par[maxs];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];

    memset(par, -1, sizeof(par));

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = sum - a[i]; j >= 0; j--)
            if (dp[j] && !dp[j + a[i]])
                dp[j + a[i]] = 1, par[j + a[i]] = i;

    int cur = 0;
    for (int i = sum / 2; i >= 0; i--)
        if (dp[i])
        {
            cur = i;
            break;
        }

    vector<int> one, two;
    vector<bool> vis(n + 1, false);

    while (cur > 0)
    {
        int idx = par[cur];
        one.pb(idx);
        vis[idx] = true;
        cur -= a[idx];
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            two.pb(i);

    cout << one.size() << ' ' << two.size() << '\n';
    for (int i : one)
        cout << i << ' ';
    cout << '\n';
    for (int i : two)
        cout << i << ' ';
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
