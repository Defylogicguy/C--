/*************************
 Author: Defy logic guy
21:58:49 - 22/11/2025
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
        os << (it == c.begin() ? "" : " ") << *it;
    return os << "";
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
#define NAME "BOTTLES"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n < k)
    {
        cout << n << ' ' << accumulate(all(a), 0ll) << '\n';
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        return;
    }
    vector<int> dp(n + 1, LLONG_MAX), par(n + 1, 0);
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        while (dq.size() and dq.front() < i - k)
            dq.pop_front();
        if (i <= k)
            dp[i] = a[i];
        else if (dq.size())
        {
            dp[i] = a[i] + dp[dq.front()];
            par[i] = dq.front();
        }
        while (dq.size() and dp[dq.back()] >= dp[i])
            dq.pop_back();
        dq.pb(i);
    }
    int idx = -1, ans = LLONG_MAX;
    for (int i = max(1ll, n - k + 1); i <= n; i++)
        if (dp[i] < ans)
            ans = dp[i], idx = i;
    vector<int> rm;
    while (idx > 0)
    {
        rm.pb(idx);
        idx = par[idx];
    }
    reverse(all(rm));
    idx = 0;
    int sum = 0;
    vector<int> v;
    // cerr << rm << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (rm[idx] == i)
            idx++;
        else
            v.pb(i), sum += a[i];
    }
    cout << v.size() << ' ' << sum << '\n'
         << v;
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
