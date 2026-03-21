/*************************
  Author: Defy logic guy
  15:30:03 - 14/03/2026
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
#define NAME "CNT"

const int maxn = 4e5 + 5;
int tree[4 * maxn];

void upd(int idx, int l, int r, int pos)
{
    if (l == r)
    {
        tree[idx]++;
        return;
    }
    int m = l + r >> 1;
    if (pos <= m)
        upd(2 * idx, l, m, pos);
    else
        upd(2 * idx + 1, m + 1, r, pos);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int get(int idx, int l, int r, int ql, int qr)
{
    if (qr < l or r < ql)
        return 0;
    if (ql <= l and r <= qr)
        return tree[idx];
    int m = l + r >> 1;
    return get(2 * idx, l, m, ql, qr) + get(2 * idx + 1, m + 1, r, ql, qr);
}

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pf(n + 1, 0);
    partial_sum(all(a), pf.begin() + 1);
    vector<int> c;
    for (int i = 0; i < pf.size(); i++)
    {
        c.pb(pf[i]);
        c.pb(pf[i] - s);
        c.pb(pf[i] + s);
    }

    sort(all(c));
    c.erase(unique(all(c)), c.end());
    auto f = [&](int x)
    { return lower_bound(all(c), x) - c.begin(); };

    int ans = 0;
    upd(1, 0, c.size() - 1, f(pf[0]));
    for (int i = 1; i <= n; i++)
    {
        ans += get(1, 0, c.size() - 1, 0, f(pf[i] - s) - 1);
        ans += get(1, 0, c.size() - 1, upper_bound(all(c), pf[i] + s) - c.begin(), c.size() - 1);
        upd(1, 0, c.size() - 1, f(pf[i]));
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
