/*************************
  Author: Defy logic guy
  11:00:56 - 23/11/2025
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
#define NAME "2169"

struct node
{
    int l, r, idx;
};

void solve()
{
    int n;
    cin >> n;
    vector<node> a(n);
    vector<int> r;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].l >> a[i].r;
        a[i].idx = i;
        r.pb(a[i].r);
    }

    sort(all(r));
    r.erase(unique(all(r)), r.end());
    auto gget = [&](int x)
    {
        return lower_bound(all(r), x) - r.begin() + 1;
    };

    sort(all(a), [](const node &a, const node &b)
         { return a.l == b.l ? a.r > b.r : a.l < b.l; });

    int m = r.size();
    vector<int> f(m + 2, 0);

    auto upd = [&](int i, int v)
    {
        while (i <= m)
        {
            f[i] += v;
            i += i & -i;
        }
    };

    auto get = [&](int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += f[i];
            i -= i & -i;
        }
        return res;
    };

    vector<int> one(n), two(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int pos = gget(a[i].r);
        one[a[i].idx] = get(pos);
        upd(pos, 1);
    }

    fill(all(f), 0);
    for (int i = 0; i < n; i++)
    {
        int pos = gget(a[i].r);
        two[a[i].idx] = i - get(pos - 1);
        upd(pos, 1);
    }

    for (int x : one)
        cout << x << ' ';
    cout << '\n';
    for (int x : two)
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
