/*************************
  Author: Defy logic guy
  16:03:00 - 18/10/2025
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
#define NAME "SHELF"

struct item
{
    int l, r, h;
    item(int l = 0, int r = 0, int h = 0) : l(l), r(r), h(h) {}
    bool operator<(const item &other) { return h < other.h; }
};

struct node
{
    int x, h;
    node(int x = 0, int h = 0) : x(x), h(h) {}
    bool operator<(const node &other) { return x < other.x; }
    bool operator>(const node &other) { return x > other.x; }
};

void solve()
{
    int n;
    cin >> n;
    vector<item> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].l >> a[i].r >> a[i].h;
    sort(rall(a));
    set<node> st;
    int ans = 0;
    for (auto &[l, r, h] : a)
    {
        node one = node(l, h), two = node(r, h);
        auto ll = st.lower_bound(one);
        auto it = ll;
        for (; it != st.end() and it->x <= two.x; it++)
            ans += it->h - one.h;
        st.erase(ll, it);
        st.insert(one);
        st.insert(two);
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
