/*************************
  Author: Defy logic guy
  14:59:29 - 29/11/2025
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
#define NAME "LMH_COVER"

struct node
{
    int l, r, id;
    node(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
};

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].l >> a[i].r, a[i].id = i + 1;
    sort(all(a), [](const node &a, const node &b)
         { return a.l ==  b.l ? a.r > b.r : a.l < b.l; });
    vector<int> v;
    int cur = x, i = 0;
    while (cur < y)
    {
        int mx = LLONG_MIN;
        int idx = -1;

        while (i < n and a[i].l <= cur)
        {
            if (a[i].r > mx)
            {
                mx = a[i].r;
                idx = a[i].id;
            }
            i++;
        }

        if (mx < cur)
        {
            cout << -1;
            return;
        }

        v.pb(idx);
        cur = mx;
    }

    cout << v.size() << '\n';
    for (int i : v)
        cout << i << '\n';
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
