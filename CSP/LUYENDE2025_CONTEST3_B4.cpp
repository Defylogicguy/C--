/*************************
  Author: Defy logic guy
  14:50:19 - 07/02/2026
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
#define NAME "LUYENDE2025_CONTEST3_B4"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] %= k;
    if (n >= k)
    {
        map<int, int> mp;
        int cur = 0;
        mp[cur] = 0;
        for (int i = 0; i < n; i++)
        {
            cur = (cur + a[i]) % k;
            if (mp.count(cur))
            {
                for (int j = mp[cur] + 1; j <= i + 1; j++)
                    cout << j << ' ';
                return;
            }
            mp[cur] = i + 1;
        }
    }
    vector<int> path;
    bool flag = false;

    function<void(int, int)> dfs = [&](int i, int cur)
    {
        if (flag)
            return;

        if (i == n)
        {
            if (path.size() && cur == 0)
                flag = true;
            return;
        }

        dfs(i + 1, cur);
        if (flag)
            return;

        path.pb(i + 1);
        dfs(i + 1, (cur + a[i]) % k);
        if (flag)
            return;

        path.pop_back();

        path.pb(-(i + 1));
        dfs(i + 1, (cur - a[i] + k) % k);
        if (flag)
            return;
        path.pop_back();
    };

    dfs(0, 0);

    if (!flag)
    {
        cout << 0 << '\n';
        return;
    }

    for (int x : path)
        cout << x << ' ';
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
